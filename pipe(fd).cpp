#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
int n;
int fd[2];
char buffer[1024];
char const *data = "WRITING TO PIPE";
pipe(fd);

write(fd[1], data, strlen(data));
if ((n=read(fd[0], buffer, 1024))>=0){

buffer[n] = 0;
printf("READ %d bytes of data from pipe %s", n, buffer);}
else {
perror("read");
exit(0);}

return 0;}
