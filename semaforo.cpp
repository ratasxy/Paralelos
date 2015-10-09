#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int thread_count;

int counter;

sem_t count_sem;
sem_t barrier_sem;

void* Algo(void* rank) {
	sem_wait(&count_sem);
	if (counter == thread_count - 1) {
	counter = 0;
	sem post(&count_sem);
	for (j = 0; j < thread_count - 1; j++)
	sem_post(&barrier sem);
	} else {
		counter++;
		sem_post(&count_sem);
		sem_wait(&barrier_sem);
	}
}

int main()
{
	long thread;
	pthread_t* thread_handles;

 	cin >> thread_count;       		

	thread_handles = malloc(thread_count*sizeof(pthread_t));

	count_sem = 1;
    barrier_sem = 0;

	for(thread=0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread], NULL, Algo, (void*) thread);

	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread], NULL);
}

