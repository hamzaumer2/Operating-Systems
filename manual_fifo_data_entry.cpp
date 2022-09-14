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

char str[256] = "HELLO WORLD";

int fifo_write;
fifo_write = open(pipe_one, O_WRONLY);

if(fifo_write<0){cout << "ERROR";}
else {
while (strcmp(str, "abort")!=0){
	cout << "Enter Text: ";
	cin>> str;
	write(fifo_write, str,  sizeof(str));
	cout << "*" << str << "*" << endl;
	}
	close(fifo_write);

}

return 0;}
