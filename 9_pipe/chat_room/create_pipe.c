#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main(){
	char * pipe1_path = "./1stPipe";
	int pipe1_flag;
	
	if(access(pipe1_path, F_OK) == 0){
		printf("Pipe 1 already exist.\n");
	}
	else{
		pipe1_flag = mkfifo(pipe1_path, 0666);
		
		if(pipe1_flag<0) {
			printf("Error in creating pipe1.\n");
		}
		else{
			printf("Pipe1 is created successfully.\n");
		}
	}
	
	char * pipe2_path = "./2ndPipe";
	int pipe2_flag;
	
	if(access(pipe2_path, F_OK) == 0){
		printf("Pipe 2 already exist.\n");
	}
	else{
		pipe2_flag = mkfifo(pipe2_path, 0666);
		
		if(pipe2_flag<0) {
			printf("Error in creating pipe2.\n");
		}
		else{
			printf("Pipe2 is created successfully.\n");
		}
	}
	
}
