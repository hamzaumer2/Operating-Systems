#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int customers[5];
int barista[4];
int freeaccessmachines[1];
int accessmachines[2];

void randomWait();
void barista_process();
void customer_process();



void main() {
   int i;
   pipe(accessmachines);
   pipe(customers);
   pipe(barista);
   pipe(freeaccessmachines); 
	
   V(accessmachines); 
	
   int num = 3; // waiting room seats = 3
   write(freeaccessmachines[1],&num,sizeof(int));
	
   if (fork() == 0) {
      srand(time(0)+1); //Random Seed  
      barista_process();
      return;
   }
   
   for (i = 1; i <= 5; i++) { // five customers
      if (fork() == 0) {
         srand(time(0)+2*i); // different random seed 
         customer_process();
         return;
      }
   }
   sleep(10);
   printf("\ndone\n\n");
   return 0;
}

void barista_process() {
   int i; 
   int num; //number of free machines
   for (i = 1; i <= 5; ++i) {
      printf("Barista %d is trying to get a customer\n",i);
      P(customers); 
      printf("Barista %d is waiting for the machine to become free\n",i);
      P(accessmachines); 
      read(freeaccessmachines[0],&num,sizeof(int));
      num++; 
      write(freeaccessmachines[1],&num,sizeof(int));
      printf("Barista %d is increasing the number of free accessmachines to %d\n",i,num);
      V(barista); 
      V(accessmachines); 
      printf("Barista is now making coffee %d\n",i);
      randomWait();	
   }
}


void customer_process() {
   int i;
   int num;
   for (i = 1; i <= 2; ++i) {
      printf("New customer is entering in queue\n");
      P(accessmachines); 
      read(freeaccessmachines[0],&num,sizeof(int));
      if (num > 0) 
      {
         num--;
         write(freeaccessmachines[1],&num,sizeof(int));
         printf("Customer left seat in waiting room. The total free accessmachines left is %d\n",num);
         V(customers); 
         V(accessmachines); 
         printf("Customer is now waiting for the coffee\n");
         P(barista); 
         printf("Customer is now getting coffee\n");
      }
      else
      {
         write(freeaccessmachines[1],&num,sizeof(int));
         V(accessmachines); 
         printf("No machines in waiting room\n");
      }
      randomWait();
   }
}

void randomWait() { // random delay 
   int delay;
   delay = random() % 9999999999;
   printf("  - wait: %d\n", delay); // debugging - value of wait time
   
}

void V(int pd[]) {
   int a=1;
   write(pd[1],&a,sizeof(int));
}

void P(int pd[]) {
   int a;
   read(pd[0],&a,sizeof(int));
}