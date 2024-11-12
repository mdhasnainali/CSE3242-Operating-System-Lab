# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(){
	pid_t my_pid, child_pid;
	
	my_pid = getpid();
	
	child_pid = fork();
	
	if(child_pid == 0){
		printf("Child Process Id: %d, Parent Process of Child: %d\n", getpid(), getppid());
	}
	else if(child_pid > 0){
		printf("Parent Pid: %d\n", my_pid);	
		sleep(120);
		wait(NULL);
	}
}
