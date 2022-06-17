//////////////Program 1: Write a program using open() system call to read the first 10 characters of an existing file “test.txt” and print them on screen.



//open.c
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int n,fd;
char buff[50];
fd=open("test.txt",O_RDONLY); //opens test.txt in read mode and the file descriptor is saved in integer fd.
printf("The file descriptor of the file is: %d\n,fd); // the value of the file descriptor is printed.
n=read(fd,buff,10);//read 10 characters from the file pointed to by file descriptor fd and save them in buffer (buff)
write(1,buff,n); //write on the screen from the buffer
}


////////Program2: To read 10 characters from file “test.txt” and write them into non-existing file “towrite.txt”

//open2.c
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int n,fd,fd1;
char buff[50];
fd=open("test.txt",O_RDONLY);
n=read(fd,buff,10);
fd1=open("towrite.txt",O_WRONLY|O_CREAT,0642);//use the pipe symbol (|) to separate O_WRONLY and O_CREAT
write(fd1,buff,n);
}