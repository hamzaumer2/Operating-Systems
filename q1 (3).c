//HAMZA UMER
//OS LAB 9
//QUESTION 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *threadOne(void *vargp)
{
    sleep(1);
	printf("\nINSIDE THREAD ONE");
    printf("\nROLL NUMBER: 200789");
    return NULL;
}


void *threadTwo(void *vargp)
{
    sleep(1);
	printf("\n\nINSIDE THREAD 2");
    printf("\nCNIC: 61101-*******-3");
    printf("\nVILLAGE: FSD");
    return NULL;
}


int main()
{
    pthread_t thread_id, thread_id2;

    pthread_create(&thread_id, NULL, threadOne, NULL);
    pthread_create(&thread_id2, NULL, threadTwo, NULL);

	void *t1;
	void *t2;

    pthread_join(thread_id, &t1);
    pthread_join(thread_id2, &t2);

    pthread_exit(NULL);
}
