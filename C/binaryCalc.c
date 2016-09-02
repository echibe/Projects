#include <stdio.h>
 
int main()
{
	printf("Binary Calculater v1.2 - Elliot Chibe\n\n");
  int n, c, k, m, i;
  int validNum = 0;
  int validDig = 0;
  int max =1;
  int go = 1;
  int done = 0;
  
  while(!validDig){
  	printf("How many digits would you like to use?(Max 31)");
  	scanf("%d", &m);
	if(m>31 || m==0){
		validDig=0;
		printf("You have entered an invalid amount of digits.\nPlease try again (valid range -> [1,31])\n\n");
	}
	else{
		validDig=1;
	}
  }
  
  for(i=0; i<m; i++){
	  max=max*2;
  }
  max=max-1; 
   
  while(!done){
	  validNum = 0;
	  while(!validNum && !done){
		  printf("\nEnter an integer in decimal number system (0 for exit)\n");
		  scanf("%d", &n);
		  if(n>max || n<=0){
			  if(n==0){
				  done = 1;
				  printf("Exiting..");
			  }
			  else{
			  	validNum=0;
			  	printf("The integer you entered is too large for %d binary digits.\nPlease try again", m);
			  }
		  }
		  else{
			  validNum=1;
		  }
	  }
	if(!done){
	  printf("%d in binary number system is:\n", n);
		  for (c = (m-1); c >= 0; c--)
		  {
		    k = n >> c;
		    if (k & 1)
		      printf("1");
		    else
		      printf("0");
		  }  
	  }
  }
  printf("\n");
 
  return 0;
}