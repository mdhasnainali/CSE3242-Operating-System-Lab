# include <stdio.h>
# include <unistd.h>

int main(){
	pid_t my_pid, child_pid, parent_pid;
	
	child_pid = fork();
	my_pid = getpid();
	parent_pid = getppid();
	
	if(child_pid == 0){
		printf("Child Process Id: %d, Parent Process of Child: %d\n", getpid(), getppid());
		
		sleep(10);
		
		printf("Child Process Id: %d, Parent Process of Child: %d\n", getpid(), getppid());
	}
	
	printf("Parent Pid: %d\n", my_pid);	
}
