# include<stdio.h>
# include<unistd.h>
# include<sys/wait.h>
# include<sys/prctl.h>

int main(){
	pid_t child;
	
	child = fork();
	
	if(child == 0){
		prctl(PR_SET_NAME, "child_1", 0, 0, 0);
		sleep(50);
	}
	else if(child>1){
		child = fork();
		S
		if(child == 0){
			prctl(PR_SET_NAME, "child_2", 0, 0, 0);
			sleep(50);
		}
		else if(child>1){
			child = fork();
			
			if(child == 0){
				prctl(PR_SET_NAME, "child_3", 0, 0, 0);
				sleep(50);
			} 
		}
	}
	wait(NULL);
	wait(NULL);
	wait(NULL);
} 
