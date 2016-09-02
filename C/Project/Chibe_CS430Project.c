//Elliot Chibe - CS430 Project - April 20th, 2015

#include <stdio.h>
#include <stdlib.h>

int main(void);
FILE *get_datafile(int argc, char *argv[]);

//global variables
int numLines = 0;

typedef struct{
	int jobNum;
	int start;
	int finish;
	int assigned;
} JOB;

typedef struct{
	int numberOfJobs;
	JOB jobs[100];
} MACHINE;

int main(){
	FILE *datafile = fopen("input.txt", "r");;
	char *buffer = NULL;
	int numMachines, words_read, i, j=0, k;
	size_t buffer_len = 0, bytes_read = 0;
	
	//Get the number of lines to initialize the struct array
	bytes_read = getline(&buffer, &buffer_len, datafile);
	while(bytes_read!=-1){
		numLines++;
		bytes_read = getline(&buffer, &buffer_len, datafile);
	}	
	JOB job[numLines];
	
	//Reinitialize the file to read the values of the jobs
	FILE *datafile2 = fopen("input.txt", "r");;
	buffer_len = 0, bytes_read = 0;

	bytes_read = getline(&buffer, &buffer_len, datafile2);
	words_read = sscanf(buffer, "%d", &numMachines);
	bytes_read = getline(&buffer, &buffer_len, datafile2);
	
	//Assign values to the structs attributes from the input file
	while(bytes_read!=-1){
		words_read = sscanf(buffer, "%d	%d	%d", &job[j].jobNum, &job[j].start, &job[j].finish);
		job[j].assigned=0;
		bytes_read = getline(&buffer, &buffer_len, datafile2);
		j++;
	}
	
	//visualize before the jobs are sorted
	printf("** Before SORT **\n\n");
	for(i=0; i<numLines-1; i++){
		printf("%d: ", i);
		for(j=0; j<job[i].start; j++){
			printf(" ");
		}
		for(k=0; k<(job[i].finish-job[i].start);k++){
			printf("-");
		}
		printf("\n");
	}
	
	//sort the array of structs by start time (Selection sort)
	for (i = 0; i < numLines; ++i){
		int min, tempNum, tempStart, tempFinish;
		min = i;
		for (j = i+1; j < numLines; j++){
			//Compare two jobs to see if they are out of order by start time
			if (job[j].start < job[min].start)
			min = j;
		}
			
		//Swap the attributes of the jobs
		tempNum = job[i].jobNum;
		tempStart = job[i].start;
		tempFinish = job[i].finish;
		
		job[i].jobNum = job[min].jobNum;
		job[i].start = job[min].start;
		job[i].finish = job[min].finish;
		
		job[min].jobNum = tempNum;
		job[min].start = tempStart;
		job[min].finish = tempFinish;
	}	
	
	//visualize sorted jobs
	printf("\n\n** AFTER SORT **\n\n");
	for(i=0; i<numLines-1; i++){
		printf("%d: ", job[i].jobNum);
		for(j=0; j<job[i].start; j++){
			printf(" ");
		}
		for(k=0; k<(job[i].finish-job[i].start);k++){
			printf("-");
		}
		printf("\n");
	}
	printf("\n\n");
	
	//Assign jobs to machines
	MACHINE machine[numMachines];
	int lastFinish;	
	for(i=0; i<numMachines; i++){
		machine[i].numberOfJobs=0;
		lastFinish=0;
		k=0;
		for(j=0; j<numLines; j++){
			//the job must not be already assigned and start after the previous one finished
			if((job[j].start >= lastFinish) && (job[j].assigned==0)){
				machine[i].jobs[k]=job[j];
				//incriment the number of jobs
				machine[i].numberOfJobs++;
				//set the job last assigned
				job[j].assigned=1;
				//set the running finished time to the last job's finish time
				lastFinish=job[j].finish;
				k++;
			}	
		}
	}
	
	//Output the jobs each machine will get
	printf("\n\n");	
	for(i=0; i<numMachines; i++){
		printf("Machine %d gets jobs: ", i);
		for(j=0; j<machine[i].numberOfJobs; j++){
			printf("%d ", machine[i].jobs[j].jobNum);
		}
		printf("\n");
	}
	
	//visualize by machine after assignment
	printf("\n\n** AFTER ASSIGNMENT **\n\n");
	int l, runningStart;
	for(i=0; i<numMachines; i++){
		printf("M%d: ", i);
		runningStart=0;
		for(j=0; j<machine[i].numberOfJobs; j++){		
			for(k=0; k<machine[i].jobs[j].start-runningStart; k++){		
				printf(" ");
			}
			printf("|");
			for(l=0; l<(machine[i].jobs[j].finish-machine[i].jobs[j].start);l++){
				if((machine[i].jobs[j].finish-machine[i].jobs[j].start)/2==l){
					//Prints out the number of the job in the middle 
					printf("%d", machine[i].jobs[j].jobNum);
				}
				printf("-");
			}
			runningStart=machine[i].jobs[j].finish;
			printf("|");	
		}
		printf("\n");
	}
	return 0;
}






