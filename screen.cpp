#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{

char * pipe_display = "/tmp/myfifo";//FILE PATH OF PIPE
    mkfifo(pipe_display, 0777);





    mkfifo(pipe_display, 0777);
    char buffer[256] = "hello world";
    int fifoDisplay;
    fifoDisplay = open(pipe_display, O_RDONLY);
    if (fifoDisplay < 0)
    {
        cout << "Error opening pipe_display file" << endl;
        return 1;
    }
    else
    {
        buffer[0] = '0';
        while (strcmp(buffer, "abort") != 0)
        {
            read(fifoDisplay, buffer, sizeof(buffer));
            cout << "Text from Client/Server:" << buffer << endl;
        }
        unlink(pipe_display);
    }
    return 0;
}
