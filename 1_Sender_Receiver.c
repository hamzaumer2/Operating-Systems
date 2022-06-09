/*The entire IPC process will consist of three programs:
Program1: to create a named pipe
Program2: process that will write into the pipe (sender process)
Program3: process that will receive data from pipe (receiver process)
*/
//Program1: Creating fifo/named pipe ( 1.c )

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>        
int main()
        {
               int res;
               res = mkfifo("fifo1",0777); //creates a named pipe with the name fifo1
               printf("named pipe created\n");
        }
		//Now compile and run this program.
		
		
		//Step 2 is to create a process which will use this pipe to send data. The below program will do that.

//Program2: Writing to a fifo/named pipe ( 2.c )

#include<unistd.h>
        #include<stdio.h>
        #include<fcntl.h>
        int main()
        {
                    int res,n;
                    res=open("fifo1",O_WRONLY);
                    write(res,"Message",7);
                    printf("Sender Process %d sent the data\n",getpid());
        }
		
		//Compile this program as
//$gcc -o 2 2.c
//Note: If you run this you will not see any output

//The third step is to create the receiver process. The below program does so.
//Program 3: Reading from the named pipe ( 3.c )

 #include<unistd.h>
        #include<stdio.h>
        #include<fcntl.h>
        int main()
        {
                    int res,n;
                    char buffer[100];
                    res=open("fifo1",O_RDONLY);
                    n=read(res,buffer,100);
                    printf("Reader process %d started\n",getpid());
                    printf("Data received by receiver %d is: %s\n",getpid(), buffer);
        }


//Compile the program as
//$ gcc -o 3 3.c
//Therefore, run both the object files simultaneously as
//./2 & ./3
//and you will see the output as