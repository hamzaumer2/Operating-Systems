








#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
int main()
{
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named pipe
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    char arr1[180], arr2[180];
    while (1)
    {
        // Opening pipe for write only
        fd = open(myfifo, O_WRONLY);

        // Take an input  from user.
        fgets(arr2, 180, stdin);

        // Writing the input  on pipe and close it
        write(fd, arr2, strlen(arr2)+1);
        close(fd);

        // Open pipe for Read only
        fd = open(myfifo, O_RDONLY);

        // Read from pipe
        read(fd, arr1, sizeof(arr1));

        // Print the read message
        printf("RAJA GEE: %s\n", arr1);
        close(fd);
    }
    return 0;
}
