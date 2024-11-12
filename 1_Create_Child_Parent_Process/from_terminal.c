# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<sys/wait.h>
# include<sys/prctl.h>

int main(int args, char* argv[]){
	printf("Total Process: %d\n", args-2);

	if (args-2 != atoi(argv[1])){
		printf("Required process and number of arguments are not same.");
		exit(-1);
	}
	
	for(int i=0;i<args-2;i++){
		pid_t child;
		child = fork();
		if(child == 0){
			prctl(PR_SET_NAME, argv[i+2], 0, 0, 0);
			sleep(50);
		}
	}
	
	
	for(int i=0;i<args;i++){
		wait(NULL);
	}
	 
} 
