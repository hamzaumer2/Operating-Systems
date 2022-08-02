//HAMZA UMER
//OS LAB 8 QUESTION 2 PART B
//readfirst.c

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    char * myfifo2 = "/tmp/myfifo";//FILE PATH OF PIPE


    mkfifo(myfifo2, 0777);//MAKING PIPE

char write2[50], read2[50];

   while (1)
    {//READING THE CONTENT OF FIRST PROCESS
        int secondprocess = open(myfifo2,O_RDONLY);//OPENING FIRST PIPE
        read(secondprocess, read2, 50);
        printf("FIRST PROCESS: %s\n", read2);
        close(secondprocess);//CLIOSING PIPE

        secondprocess = open(myfifo2,O_WRONLY);//OPENING SECOND PIPE TO WRITE AND SEND DATA TO FIRST PROCESS
        printf("\nYou are in Second Process. Write Something: ");
	fgets(write2, 50, stdin);
        write(secondprocess, write2, strlen(write2)+1);
        close(secondprocess);//CLOSING SECOND PIPE
    }
    return 0;
}
