// Effect of wait in child and parent process relationship

#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t my_pid, child_pid, parent_pid;

    child_pid = fork();
    my_pid = getpid();
    parent_pid = getppid();

    if(child_pid == 0){
        printf("__Child Process__\n");
        printf("1Child Pid: %d, My Pid: %d, Parent Pid: %d\n", child_pid, my_pid, parent_pid);
    }
    else if(child_pid > 0){
        printf("__Parent Process__\n");
        printf("2Child Pid: %d, My Pid: %d, Parent Pid: %d\n", child_pid, my_pid, parent_pid);
    }

    return 0;
}

