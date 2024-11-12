# include <stdio.h>
# include <unistd.h>

int main(){
	for(int i=0;i<10;i++){
		printf("Hello from new process\n");
		sleep(10);
	}
}
