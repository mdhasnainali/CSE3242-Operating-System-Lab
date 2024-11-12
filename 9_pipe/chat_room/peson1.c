#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void read_pipe() {
    char buffer[1000];
    char *pipe_path = "/home/shakil/Documents/Chat_Room/1stPipe";
    do {
        int pipe_fd = open(pipe_path, O_RDONLY);
        int bytes_read = read(pipe_fd, &buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';
        write(STDOUT_FILENO, buffer, strlen(buffer));
        close(pipe_fd);
    } while(strcmp(buffer, "bye\n") != 0);
    exit(0);
}

void write_pipe() {
    char buffer[1000];
    char *pipe_path = "/home/shakil/Documents/Chat_Room/2ndPipe";
    do {
        int pipe_fd = open(pipe_path, O_WRONLY);
        int bytes_read = read(STDIN_FILENO, &buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';
        write(pipe_fd, buffer, strlen(buffer));
        close(pipe_fd);
    } while(strcmp(buffer, "bye\n") != 0);
    exit(0);
}

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void*)read_pipe, NULL);
    pthread_create(&tid2, NULL, (void*)write_pipe, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}