#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


float average;
int minimum;
int maximum;

int count = 0;
int *values;

void thread1_controller(){
	average = 0;

	for(int i=0;i<count;i++){
		average += values[i];
	}
	
	average = average/count;
}

void thread2_controller(){
	minimum = 99999999;
	for(int i=0;i<count;i++){
		if(minimum > values[i]){
			minimum = values[i];
		}
	}
}

void thread3_controller(){
	maximum = 0;
	for(int i=0;i<count;i++){
		if(maximum < values[i]){
			maximum = values[i];
		}
	}
}


int main(int argc, char* argv[]){

	count = argc - 1;
	values = (int*) malloc(count * sizeof(int));
	for (int i=0;i<count;i++){
		values[i] = atoi(argv[i+1]);
	} 

	pthread_t thread1, thread2, thread3;
	
	pthread_create(&thread1, NULL, (void*)thread1_controller, NULL);
	pthread_create(&thread2, NULL, (void*)thread2_controller, NULL);
	pthread_create(&thread3, NULL, (void*)thread3_controller, NULL);
	
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	
	
	printf("Averages: %.2f\n", average);
	printf("Minimum: %.d\n", minimum);
	printf("Maximum: %.d\n", maximum);
}


