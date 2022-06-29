
////////////////////////Program1: To write some data on the standard output device (by default – monitor)//////////////

#include<unistd.h>
int main()
{
write(1,"hello\n",6); //1 is the file descriptor, "hello\n" is the data, 6 is the count of characters in data
}

//////////////////Program2/////////////////////////
#include<stdio.h
#include<unistd.h>
int main()
{
int count;
count=write(1,"hello\n",6);
printf("Total bytes written: %d\n",count);



}

//////////////////Program3/////////////////////////

#include<unistd.h>
int main()
{
write(1,"hello\n",60); //the bytes to be printed (third parameter) are more than the data specified in 2nd parameter
}

//////////////////Program4//////////////////////////////////////////////////

#include<unistd.h>
int main()
{
write(1,"hello\n",3);//the bytes to be printed (third parameter) are less than the data specified in 2nd parameter
}


//////////////////Program5////////////////////////////////////////////////////////////////////////////////////////////////////
#include<unistd.h>
#include<stdio.h>
int main()
{
int count;
count=write(3,"hello\n",6); //the file descriptor is not one of the pre-specified ones i.e., 0, 1 or 2
printf("Total bytes written: %d\n",count);
}


////////Program 6: To read data from the standard input device and write it on the screen


//read.c
#include<unistd.h>
int main()
{
char buff[20];
read(0,buff,10);//read 10 bytes from standard input device(keyboard), store in buffer (buff)
write(1,buff,10);//print 10 bytes from the buffer on the screen
}


///////////////Program 7: To read data from the standard input device and write it on the screen


#include<unistd.h>
int main()
{
int nread;
char buff[20];
nread=read(0,buff,10);//read 10 bytes from standard input device(keyboard), store in buffer (buff)
write(1,buff,nread);//print 10 bytes from the buffer on the screen
}


//Reference
//https://dextutor.com/write-read-system-call/