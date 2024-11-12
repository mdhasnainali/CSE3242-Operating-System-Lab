#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pipe_fd[2];
    char *msg = "Do not wait for me";
    char read_msg[50];
    pipe(pipe_fd);
    pid_t child_pid = fork();

    if(child_pid == 0) { // Child process
        int parent_pid = getppid();
        close(pipe_fd[0]); // Close read end before writing
        write(pipe_fd[1], msg, strlen(msg));
        sleep(1); // Give some time to the parent to read the message and process it
        if(parent_pid == getppid()) { // parent is still alive
            for(int i = 0; i < 10; i++) {
                printf("Child: Parent is waiting for me.\n");
                sleep(1);
            }
        }
        else { // parent passed away
            for(int i = 0; i < 10; i++) {
                printf("Child: Parent passed away. I am an orphan.\n");
                sleep(1);
            }
        }
    }
    else { // parent process
        close(pipe_fd[1]); // close write end before reading
        read(pipe_fd[0], read_msg, sizeof(read_msg));
        printf("Parent: I have a message from child - %s\n", read_msg);
        if(strcmp(read_msg, "Do not wait for me") == 0) {
            printf("Okay, I am not waiting. Bye\n");
            exit(0);
        }
        else {
            for(int i = 0; i < 10; i++) {
                printf("Parent: Waiting...\n");
                sleep(2);
            }
            wait(NULL);
        }
    }
}
