#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int x = 5;
int y = 10;
int result = 0;

void thread1_controller(){
	for(int i =0; i<10;i++){
		result += x + y;
		printf("A + B: %d\n", result);
	}
}

void thread2_controller(){
	for(int i =0; i<10;i++){
		result += x - y;
		printf("A- B: %d\n", result);
	}
}


int main(){

	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, (void*)thread1_controller, NULL);
	pthread_create(&thread2, NULL, (void*)thread2_controller, NULL);
	
	
	pthread_join(thread1, NULL);
	pthread_join(thread1, NULL);
}


