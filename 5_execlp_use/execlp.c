# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(){
	pid_t child_pid;
	
	child_pid = fork();
	
	if(child_pid == 0){
		execlp("./test", "test_exe", NULL); 
	}
	else if(child_pid > 0){
		wait(NULL);
	}
}
