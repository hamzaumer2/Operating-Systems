#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;
int main(){
char * pipe_one = "/tmp/myfifo";

char str[256];
int fifo_read = open(pipe_one, O_RDONLY);
if(fifo_read<0){cout << "ERROR PIPE MAKING";}
else {
	while(strcmp(str, "abort")!=0){
	read(fifo_read, str, sizeof(str));
	cout << "Text: "<< str << endl;
	}
	close(fifo_read);

}
return 0;

}
