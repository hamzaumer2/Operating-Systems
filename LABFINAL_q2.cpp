
//HAMZA UMER
//OS LAB FINAL EXAM
// QUESTION 2/4


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

using namespace std;
pthread_t pid1, tid2;


typedef struct CharCheck {

    char c;
    char* fileName;

} no_of_chars;

pthread_mutex_t count = PTHREAD_MUTEX_INITIALIZER;
int sum = 0;

void* CountFile(void* threadarg);

int main(int argc, const char* argv[]) {

    pthread_t threads[argc - 2];
    int chck, chck2, t;
    no_of_chars cf;

    for (t = 0; t < argc - 1; t++) {//FOR LOOP CREATED. MAKING 2 THREADS. ONE FOR EACH FILE

        cf.c = argv[1][0];
        cf.fileName = (char*)argv[t + 2];

        chck = pthread_create(&threads[t], NULL, CountFile, (void*)&cf);

        if (chck) {

            exit(-1);
        }
        printf("%d character in file: %s\n", sum, argv[t]);
    }

    return 0;
}



    void* CountFile(void* threadarg) {

        FILE* in;
        no_of_chars* cf;
        char c;
        int counter = 0;

        cf = (no_of_chars*)threadarg;
        in = fopen(cf->fileName, "");



        while (fscanf(in, "%c", &c) != EOF) {


                counter += 1;


        }

        fclose(in);

        pthread_mutex_lock(&count);
        sum += counter;
        pthread_mutex_unlock(&count);

        pthread_exit(NULL);
    }


//int main(int argc, string** argv)
//{


//    pthread_create(tid1, NULL, CountFile, argv[1]);
//    pthread_join(tid1,NULL);
//    pthread_create(tid2, NULL, CountFile, argv[2]);
//    pthread_join(tid2,NULL);

//}


















