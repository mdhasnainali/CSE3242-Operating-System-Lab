# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(){
	pid_t my_pid, child_pid, parent_pid;
	
	child_pid = fork();
	my_pid = getpid();
	parent_pid = getppid();
	
	if(child_pid == 0){
		printf("Child Process Id: %d\n", getpid());
		
		while(1){
			printf("Child");
		}
	}
	
	printf("Parent Pid: %d\n", my_pid);	
	wait(NULL);
}
