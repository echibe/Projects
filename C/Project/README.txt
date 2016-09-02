README

The source code is written in C. There are no command line arguments needed to complete the program. Just compile and run.
The input file is in the following format:
	a. The first line is the number of machines m.
	b. The following lines are the list of jobs to be assigned in the following format:
			Job number		Start time		Finish time
		
To compile and run:
	1. Ensure that the source input.txt file is in the same directory as the C code
	2. Compile C source code using gcc
	3. Run via ./a.out

The first visualization in the output is the unsorted raw data 
The second visualization in the output is the sorted data (by start time)
The next piece of information shows the assignents of jobs by number to each machine
Finally, the last visualization shows a visualization of the jobs per machine