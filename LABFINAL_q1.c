#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define sleeping 2
#define studying 1
#define EATING 0

int state[N];

sem_t mutex, S[N];

int slices = 10;

void test(int slices)
{
    if (state[slices] == studying) {

        state[slices] = EATING;


        printf("Student %d takes pizza slice\n",slices + 1);
        slices--;

        printf("Student %d is Eating\n", slices + 1);

        sem_post(&S[slices]);
    }
}

void eats_pizza(int slices)
{

    sem_wait(&mutex);

    state[slices] = studying;

    printf("Student %d is studying and wants pizza\n", slices + 1);


    test(slices);

    sem_post(&mutex);


    sem_wait(&S[slices]);

}

void order(int slices)
{

    sem_wait(&mutex);


    state[slices] = sleeping;

    printf("Student %d ordering pizza", slices + 1);
    printf("Student %d is sleeping\n", slices + 1);
    slices = 10;


    sem_post(&mutex);
}

void* Student(void* num)
{

    while (1) {

        int* i = num;

        eats_pizza(*i);

            order(*i);

    }
}

int main()
{

    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < N; i++)

        sem_init(&S[i], 0, 0);

    for (i = 0; i < N; i++) {


        pthread_create(&thread_id[i], NULL,
            Student, &slices);

        printf("Student %d is sleeping\n", i + 1);
    }

    for (i = 0; i < N; i++)

        pthread_join(thread_id[i], NULL);
}