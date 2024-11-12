#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void thread_controller(){
	fork();
	execlp("./test", "test", NULL);
	printf("Hello from the thread\n");
	sleep(100);
}


int main(){
	pthread_t thread;
	
	pthread_create(&thread, NULL, (void*)thread_controller, NULL);
	
	printf("I am from the main: %d\n", getpid());
	
	pthread_join(thread, NULL);
	sleep(100);
}


