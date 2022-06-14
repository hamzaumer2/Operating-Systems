#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
	int a = *((int*)vargp);
	printf("%d",a);
	//void *status="Hellofromthread";
	sleep(1);
	printf("Printing from Thread \n");
	pthread_exit((void*)a);
}

int main()
{
	pthread_t thread_id1,thread_id2;
	void *ret;
	int sum = 1234;
	printf("Before Thread\n");
	pthread_create(&thread_id1, NULL, myThreadFun, (void*)&sum);
	//pthread_create(&thread_id2, NULL, myThreadFun, NULL);
	pthread_join(thread_id1, (void*)&ret);
	printf("Status from thread: %d \n",(int)ret);
	//pthread_join(thread_id2, NULL);
	printf("After Thread\n");
	pthread_exit(NULL);
}