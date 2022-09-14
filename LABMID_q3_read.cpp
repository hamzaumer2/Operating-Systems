//HAMZA UMER
//OS LAB EXAM
//READING AND OPERATING
//QUESTION 3 PART A

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char * myfifo2 = "/tmp/myfifo";//FILE PATH OF PIPE
	char * myfifo3 = "/tmp/mkfifo";


    mkfifo(myfifo2, 0777);//MAKING PIPE
    mkfifo(myfifo3, 0777);

char write2[200], read2[50], reversed[200], newmade[300], vowels[200];

   while (1)
    {//READING THE CONTENT OF FIRST PROCESS
        int secondprocess = open(myfifo2,O_RDONLY);//OPENING FIRST PIPE
	int thirdprocess = open(myfifo3, O_RDONLY);


        read(secondprocess, read2, 50);
        read(thirdprocess, read2, 50);
	printf("WRITE SENT: %s\n", read2);
        close(secondprocess);//CLIOSING PIPE
	close(thirdprocess);
	for(int i = 0 ; i < (sizeof(read2)-1) ; i++){
	if (read2[i] == 'A' || read2[i] == 'E' || read2[i] == 'I' || read2[i] == 'O' || read2[i] == 'U'|| read2[i] == 'a' || read2[i] == 'e' || read2[i] == 'i' || read2[i] == 'o' || read2[i] == 'u'){

						vowels[i] = read2[i];
						}
							}
	for(int j = 0 ; j <(strlen(read2)-1) ; j++){
	reversed[j] = read2[strlen(read2)-j];
	}

        secondprocess = open(myfifo2,O_WRONLY);//OPENING SECOND PIPE TO WRITE AND SEND DATA TO FIRST PROCESS
        thirdprocess = open(myfifo3, O_WRONLY);

	printf("\nVOWELS IN STRING ARE: ");
	write(secondprocess, vowels, strlen(vowels)+1);
	printf("\nREVERSED STRING IS: ");
	write(thirdprocess, reversed, strlen(reversed)+1);
        close(secondprocess);//CLOSING SECOND PIPE
	close(thirdprocess);
    }
    return 0;
}
