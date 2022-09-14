#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{
char * pipe_one = "/tmp/myfifo";
char * pipe_two = "/tmp/myfifo";
char * pipe_display = "/tmp/myfifo";

int fifo1, fifo2;

    mkfifo(pipe_one, 0777);
    mkfifo(pipe_two, 0777);
    char buffer[50] = "HELLO WORLD";
    //int fifo1, fifo2;

    fifo1 = open(pipe_one, O_WRONLY);
    if (fifo1 < 0)
    {
        cout << "Error opening pipe_one file" << endl;
        return 1;
    }
	else {cout << "INSIDE PIPE 1";
	}
    fifo2 = open(pipe_two, O_RDONLY);
    if (fifo2 < 0)
    {
        cout << "Error opening pipe_two file" << endl;
        return 1;
    }
	else {cout << "INSIDE PIPE2";
	unlink(pipe_two);}
        return 0;
}
