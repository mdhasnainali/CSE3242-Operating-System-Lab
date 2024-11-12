#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int bags_stock = 10;
pthread_mutex_t key;

void fibonacci_generator(){
	int quantity = rand()%10;
	
	pthread_mutex_lock(&key);
	
	printf("User trying to buy %d bag. Current stocks: %d\n", quantity, bags_stock);

	if(bags_stock>quantity){
		bags_stock = bags_stock - quantity;
		printf("Successfull checkout. Current stock: %d\n", bags_stock);
	}
	else{
		printf("Not enough in the stock\n");
	}
	
	pthread_mutex_unlock(&key);
}


int main(int argc, char* argv[]){
	
	
	pthread_t thread[7];
	
	for(int i=0;i<7;i++){
		pthread_create(&thread[i], NULL, (void*)fibonacci_generator, NULL);
	}
	
	
	for(int i=0;i<7;i++){
		pthread_join(thread[i], NULL);
	}
	
	printf("Final Stock: %d\n", bags_stock);
}


