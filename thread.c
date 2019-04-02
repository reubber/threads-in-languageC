#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void *threadFunc(void *arg){
	char *s = (char *) arg;
	
	printf("%s", s);
	
	return (void *) strlen(s);
}

int main(int argc, char *argv[]){

	pthread_t t1;
	void *res;
	int s;
	
	s = pthread_create(&t1, NULL, threadFunc, "Hello World\n");
	if(s != 0)
		fputs("Error: pthread create", stderr);
		
	printf("Message from main()\n");
	s = pthread_join(t1, &res);
	if(s != 0)
		fputs("Error: pthread_join", stderr);
	
	printf("Thread returned %ld\n", (long) res);
	
	exit(EXIT_SUCCESS);
}
