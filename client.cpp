#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{
char * pipe_one = "/tmp/myfifo";//FILE PATH OF PIPE
char * pipe_two = "/tmp/myfifo";//FILE PATH OF PIPE
char * pipe_display = "/tmp/myfifo";//FILE PATH OF PIPE



    mkfifo(pipe_one, 0777);
    mkfifo(pipe_two, 0777);
    mkfifo(pipe_display, 0777);
    char buffer[50] = "CLIENT CHAT";
    int fifo1, fifo2, fifoDisplay;
    int choice;
    fifo1 = open(pipe_one, O_WRONLY);
    if (fifo1 < 0)
    {
        cout << "Error opening pipe_one file" << endl;
        return 1;
    }
    fifo2 = open(pipe_two, O_RDONLY);
    if (fifo2 < 0)
    {
        cout << "Error opening pipe_two file" << endl;
        return 1;
    }
    fifoDisplay = open(pipe_display, O_WRONLY);
    if (fifoDisplay < 0)
    {
        cout << "Error opening pipe_display file" << endl;
        return 1;
    }
    else
    {
        do
        {
            cout << "Do you want to write message or read message? (1: Write, 2: Read, x: Exit) ";
            cin >> choice;
            if (choice == 1)
            {
                buffer[0] = '0';
                while (strcmp(buffer, "abort") != 0)
                {
                    cout << endl << "Enter text: ";
                    cin.getline(buffer, sizeof(buffer));
                    write(fifo1, buffer, sizeof(buffer));
                }
                cout << "∗" << buffer << "∗" << endl;
            }
            else if (choice == 2)
            {
                buffer[0] = '0';
                while (strcmp(buffer, "abort") != 0)
                {
                    read(fifo2, buffer, sizeof(buffer));
                    write(fifoDisplay, buffer, sizeof(buffer));
                }
            }
            else
            {
                unlink(pipe_one);
                unlink(pipe_two);
                unlink(pipe_display);
            }
        } while (choice == 1 || choice == 2);
    }
    return 0;
}
