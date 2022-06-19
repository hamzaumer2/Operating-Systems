#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<iostream>
using namespace std;

sem_t sem;

void *f1(void *arg)
{
    int* value = (int *) arg;
    int i = 1;
    sem_wait(&sem);
    // sem_getvalue(&sem, &value);
    cout<<"Customers with ID: "<<pthread_self()<< " wants: "<<*value<<" coffees."<<endl;
    pthread_exit((void*)value);
}

void cal(int temp)
{
    cout<<"Total cost = "<<static_cast<float>(temp)*2.20f <<endl;
}

int main(void)
{
    pthread_t customers[6];
    int value, i;
    sem_init(&sem, 0, 3);

    void *values;
    int temp =0;
    for(int i = 0; i < 4; i++)
    {
        cout<<"Cost of 1 coffee = $2.20 \n";
        cout<<"Type in the number of coffees: \n";
        cin>>value;
        pthread_create(&customers[i], NULL, f1, &value);
        pthread_join(customers[i], &values);
        sleep(1);
        cal(*(int *)values);
        temp++;
    }
    sleep(2);
    // cout<<"total cost = \n";
    sem_post(&sem);
    sem_getvalue(&sem, &value);
    cal(temp);
    // cout<<"Main after post sem state: " <<value<<endl;
    sleep(3);
    // cout<<"Main going to post\n";
    sem_getvalue(&sem, &value);
    cal(temp);
    // cout<<"Main after post sem state: "<<value<<endl;
    pthread_exit(0);
    return 0;
}