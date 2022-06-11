

// parent write data and child read data from parent

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int fd[2];
	if(pipe(fd) == -1) {
		printf("An error occured with opening the pipe\n");
		return 1;	
	}

	int id = fork();
	if(id == -1) {
		printf("fork failed\n");
		return 1;
	}

	if(id == 0) {
		close(fd[0]); //Not expecting to read any data in child, that is why 
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if(write(fd[1],&x,sizeof(int)) ==  -1) {
			printf("An error occured with opening the pipe\n");
			return 2;
		}
		close(fd[1]);
	} else {
		close(fd[1]);
		int y;
		if(read(fd[0],&y,sizeof(int)) == -1) {
			printf("An error occured with opening the pipe\n");
			return 2;
		}
		close(fd[0]);
		printf("Got from child process %d\n",y);
	}

	return 0;
}