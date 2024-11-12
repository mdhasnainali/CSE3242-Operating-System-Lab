#include <stdio.h>
#include <unistd.h>
#include<string.h>


int main(){
	char *msg, buffer[100];
	int n;
	
	msg = "Insert a string: ";
	write(STDOUT_FILENO, msg, strlen(msg)+1);
	n = read(STDIN_FILENO, &buffer, sizeof(buffer));
	buffer[n] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}
