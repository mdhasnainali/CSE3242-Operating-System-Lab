#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void thread_controller(){
	printf("Hello from the thread\n");
	
	fork();
	
	sleep(100);
}


int main(){
	pthread_t thread;
	
	pthread_create(&thread, NULL, (void*)thread_controller, NULL);
	
	printf("I am from the main\n");
	
	pthread_join(thread, NULL);
}


