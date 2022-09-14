//HAMZA UMER
//OS LAB FINAL EXAM
// QUESTION 4/4

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

sem_t sem;

pthread_t tid1, tid1;



struct character {

    charval* tok;


}; character p1;

void* characterthread(void* attr)





int main(void) {
    char characterval[200];
    cout << "\nEnter Characters: ";
    cin >> characterval;

    int total = 0;
    p1 = temp;


    sem_init(&sem, 0, 1);

    for (int i = 0; i = sizeof(characterval); i++) {
        pthread_create(tid1, NULL, &characterthread, characterval[i]);
        pthread_join(tid1, NULL);

        pthread_create(tid2, NULL, &characterthread, characterval[i]);
        pthread_join(tid2, NULL);
        total++;
        cout << "\nNo of Characters are: " << total;
    }


    return 0;

}


void* characterthread(void* attr) {

    char temp = (*(int*)attr);

    character* tempcharacter;

    tempcharacter = p1;

    cout << "\nCharacter is: " << p1;
}