#include <pthread.h>
#include <stdio.h>
#define NTHREADS 50

long countarray[NTHREADS];
void *imprimirHola(void*);

void *imprimirHola(void *null) {
	printf("hola %ld\n",(long) pthread_self() );
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	
	pthread_t t[NTHREADS];
	
	for (int i = 0; i < NTHREADS; i++) {
		countarray[i] = (long)i;
		pthread_create(&t[i], NULL, imprimirHola, (void*)countarray[i]);
	}
	
	for (int i = 0; i < NTHREADS; i++) {
		pthread_join(t[i],NULL);
	}
	return 0;
}


