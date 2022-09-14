//HAMZA UMER
//OS LAB MID EXAM
//WRITING DATA
//QUESTION 3 PART B

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char write1[50], read1[50];
	char * myfifo = "/tmp/myfifo";//FILEPATH OF PIPE	// ADDING THIS BECAUSE WITHOUT THIS THE PROGRAM WASNT RUNNING IN WSL

    	mkfifo(myfifo, 0777);//MAKING PIPE
    	while (1)
    		{//OPENING FIRST PIPE TO WRITE AND SEND TO SECOND PROCESS

        	int firstprocess = open(myfifo, O_WRONLY);
		printf("\nWrite Something MAX SIZE IS 50 CHARACTERS: ");
        	fgets(write1, 50, stdin);
        	write(firstprocess, write1, strlen(write1)+1);
        	close(firstprocess);//CLOSING PIPE

        	firstprocess = open(myfifo, O_RDONLY);//OPEINING PIPE TO TAKE INPUT OF SECOND PROCESS
        	read(firstprocess, read1, sizeof(read1));
		printf("DATA SENT FROM READ IS %s\n", read1);
        	close(firstprocess);//CLOSING PIPE
    			}
    	return 0;
	}
