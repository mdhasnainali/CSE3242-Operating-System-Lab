#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int x = 0;
sem_t key;

void addition(){
	sem_wait(&key);
	printf("Start Addition\n");
	for(int i=0;i<10;i++){
		x = x+1;
		printf("%d: Addition= x+1: %d\n",i,x); 
	}
	sem_post(&key);

}

void subtraction(){
	sem_wait(&key);
	printf("Start Subtraction\n");
	for(int i=0;i<10;i++){
		x = x-1;
		printf("%d: Subtraction= x-1: %d\n",i,x); 
	}
	sem_post(&key);
}

void main(){
	
	pthread_t thread1, thread2;
	
	sem_init(&key, 0, 1);
	
	pthread_create(&thread1, NULL, (void *)addition, NULL);
	pthread_create(&thread2, NULL, (void *)subtraction, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2,NULL);
}
