#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int *fibonacci_series;
int count;

void fibonacci_generator(){
	fibonacci_series = (int*) malloc(count*sizeof(int));
	
	fibonacci_series[0] = 0;
	fibonacci_series[1] = 1;
	
	for(int i=2;i<count;i++){
		fibonacci_series[i] = fibonacci_series[i-1] + fibonacci_series[i-2];
	}	
}


int main(int argc, char* argv[]){

	if(argc !=2){
		printf("Please provide the febonacci number.");
		exit(EXIT_FAILURE);
	}

	count = atoi(argv[1]);
	
	
	pthread_t thread;
	
	pthread_create(&thread, NULL, (void*)fibonacci_generator, NULL);
	pthread_join(thread, NULL);
	
	for (int i=0;i<count;i++){
		printf("%d ", fibonacci_series[i]);
	} 
	
	printf("\n");

	
}


