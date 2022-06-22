#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(){
char str[25], str2[25];
while(strcmp(str,"abort")!=0){

int fifo_write = open("pipe_one",O_WRONLY);

cin>>str2;


write(fifo_write,str2,sizeof(str2));
cout<<"text"<<str2<<endl;

close(fifo_write);

int fifo_read = open("pipe_one",O_RDONLY);

read(fifo_read,str,sizeof(str));
cout<<"text:"<<str<<endl;
close(fifo_read);
}

return 0;
}
