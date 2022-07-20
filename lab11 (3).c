//HAMZA UMER 
//BSCS 4 - B
//OS LAB11 TASK

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
int balance = 0;
pthread_mutex_t mutex1;
pthread_t t1, t2 ;

void *withdraw(void *tid)
{
pthread_mutex_lock(&mutex1);
for (int i=0; i<10; i++){
int readbalance = balance;
printf("\n\nAt time %d, the balance for withdrawal thread %d is %d", i, tid, balance);
readbalance -= 10;
sleep(1);
if(readbalance < 10){
printf("\nBALANCE LESS THAN MINIMUM. CARD BLOCKED. EXITING");
return 0;
}
balance = readbalance;
printf("\nAt time %d, the balance after withdrawal thread %d is %d", i, tid, balance);
sleep(1);
}
pthread_mutex_unlock(&mutex1);
pthread_exit(NULL);
}

void *deposit(void *tid)
{
pthread_mutex_lock(&mutex1);
for (int i=0; i<10; i++)
{
int readbalance = balance;
printf("\n\nAt time %d, the balance before depositing thread %d is %d", i, tid, balance);
readbalance += 11;
sleep(1);
balance = readbalance;
printf("\nAt time %d, the balance after depositing thread %d is %d", i, tid, balance);
sleep(1);
}
pthread_mutex_unlock(&mutex1);
pthread_exit(NULL);
} 

int main()
{
pthread_mutex_init(&mutex1, NULL);
pthread_create(&t1 ,NULL,deposit,NULL);
pthread_create(&t2 ,NULL,withdraw,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
	return 0;
}
