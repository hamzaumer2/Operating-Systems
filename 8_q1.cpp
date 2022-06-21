#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int counter = 0 ;
pthread_mutex_t mutex3;
pthread_t thread1 , thread2;
void *functionA(void *p){
int a ;
pthread_mutex_lock( &mutex3 ) ;
a=counter ; a--; counter=a ;
cout<<"Thread id : "<<pthread_self()<<" Counter Value  :  "<<counter<<endl;
pthread_mutex_unlock( &mutex3 ) ;
cout<<"unlock";
pthread_exit(NULL);
}

void *functionB(void *p){
sleep(1);

int b; int mycount=0;

while(pthread_mutex_trylock( &mutex3 ) !=0 ){
while(mycount==8){
mycount++;
}
mycount=0;
cout<<"Trying to own lock"<<endl ;
}

b=counter; b++; counter=b;
cout<<"Thread id : "<<pthread_self()<<" Counter Value  :   "<<counter<<endl;
pthread_mutex_unlock( &mutex3 );
pthread_exit(NULL);
}




int main(){
pthread_mutex_init(&mutex3 ,NULL) ;

pthread_create(&thread1 ,NULL,&functionA ,NULL);
pthread_create(&thread2 ,NULL,&functionB ,NULL);

cout<<"Thread 1 ID :   "<<thread1<<endl;
cout<<"Thread 2 ID :   "<<thread2<<endl;
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
pthread_mutex_destroy( &mutex3 ) ;

pthread_exit(NULL) ;

return 0;

}

