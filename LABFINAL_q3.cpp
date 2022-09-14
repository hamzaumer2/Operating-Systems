//HAMZA UMER
//OS LAB FINAL EXAM
// QUESTION 3/4


#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
using namespace std;

int balance = 0;
pthread_mutex_t mutex1;
pthread_t t1, t2, t3, t4;

void* withdraw(void* tid)
{
	pthread_mutex_lock(&mutex1);
	for (int i = 0; i < 10; i++) {
		int readbalance = balance;
		readbalance -= 10;
		sleep(1);
		if (readbalance < 10) {
			printf("\nBALANCE LESS THAN MINIMUM. CARD BLOCKED. EXITING");
			return 0;
		}
		balance = readbalance;
		cout << "\nBalance after withdrawl thread: " << tid << " is : " << balance;
		cout << "\n";
		sleep(0.3);
	}
	pthread_mutex_unlock(&mutex1);
	pthread_exit(NULL);
}

void* deposit(void* tid)
{
	pthread_mutex_lock(&mutex1);
	for (int i = 0; i < 10; i++)
	{
		int readbalance = balance;
		readbalance += 11;
		sleep(1);
		balance = readbalance;
		cout << "\nBalance after deposit thread: " << tid << " is : " << balance;
		sleep(0.3);
	}
	pthread_mutex_unlock(&mutex1);
	pthread_exit(NULL);
}

int main()
{
	pthread_mutex_init(&mutex1, NULL);
	pthread_create(&t1, NULL, deposit, NULL);
	pthread_create(&t3, NULL, deposit, NULL);
	pthread_create(&t2, NULL, withdraw, NULL);
	pthread_create(&t4, NULL, deposit, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	return 0;
}
