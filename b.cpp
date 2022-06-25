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
int res;

char * myfifo = "/tmp/myfifo";

mkfifo("pipe_one",0777);


while(strcmp(str,"abort")!=0){

int fifo_write=open("pipe_one",O_WRONLY);

cin>>str;
write(fifo_write,str,sizeof(str));
cout<<""<<str<<""<<endl;
close(fifo_write);


int fifo_read=open("pipe_one",O_RDONLY);

read(fifo_read,str2,sizeof(str2));
cout<<""<<str2<<""<<endl;


close(fifo_read);
}

return 0;
}
