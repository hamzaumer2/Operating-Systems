//HAMZA UMER
//OS LAB 9
//QUESTION 3

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int arr[30];

void *calc(void *arg){

  int sum = 0, pro = 1;
  for(int i = 0; i < 30; i++){
    sum += arr[i];
    pro = pro*arr[i];
  }
	printf("\nSUM of given ARRAY values is: %d", sum);
        printf("\nPRODUCT of given ARRAY values is: %d", pro);
        pthread_exit(0);
}


int main(){
int value_arr;
for (int i = 0 ; i < 30 ; i++){
printf("\nEnter Array Value Number %d:  ", i+1);
scanf("%d", &value_arr);
arr[i] = value_arr;
}
pthread_t computation;
pthread_create(&computation, NULL, calc, (void*)arr);
pthread_join(computation, NULL);

}
