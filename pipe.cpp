#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

int main()
{
int res;
res=mkfifo("fifoa",0777);
int rf=mkfifo("fifob",0777);
printf("named pipe");
if (rf < 0){
printf( "\nNO PIPE CREATED");
}
}
