#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pthread_t thread1, thread2;

void signal_handler(int sig){
	printf("Recived signal: SIGUSR1(%d)\n", sig);
}

void thread1_controller(){
	sleep(1);
	printf("Sending signal from thread1...\n");
	pthread_kill(thread2, SIGUSR1);
}

void thread2_controller(){
	signal(SIGUSR1, signal_handler);
	printf("Waiting for signal in thread2...\n");
	
	while(1){
		sleep(2);
	}
}


int main(){
	
	pthread_create(&thread1, NULL, (void*)thread1_controller, NULL);
	pthread_create(&thread2, NULL, (void*)thread2_controller, NULL);
	
	
	pthread_join(thread1, NULL);
	pthread_join(thread1, NULL);
	// sleep(100);
}


