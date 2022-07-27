//HAMZA UMER
//OS LAB 9
//QUESTION 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


typedef struct thread_data {
   int a, b, sum;

} thread_data;


void *t1(void *arg)
{
   printf("\nINSIDE THREAD, RETURNING SUM TO PARENT");

   thread_data *tdata=(thread_data *)arg;

   int a=tdata->a, b=tdata->b, sum=a+b;

   tdata->sum=sum;
   pthread_exit(NULL);
}




int main()
{
   pthread_t tid;
   thread_data tdata;
   int first, second;


printf("\nENTER FIRST NUMBER: ");
scanf("%d", &first);

printf("\nENTER SECOND NUMBER: ");
scanf("%d", &second);

   tdata.a=first, tdata.b=second;
   printf("\nBEFORE PASSING DATA TO THREAD");


   pthread_create(&tid, NULL, t1, (void *)&tdata);
   pthread_join(tid, NULL);


   printf("\nBACK IN PARENT TO PRINT SUM: ");
   printf("%d + %d = %d\n", tdata.a, tdata.b, tdata.sum);

   return 0;
}
