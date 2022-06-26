#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
int fd[2];
pid_t childpid;
char string[] = "HELLO WORLD";
char readbuffer[80];
int result = pipe(fd);

if(result < 0){cout << "\nERROR MAKING FILE";
		exit(1);}

childpid = fork();
wait(NULL);
if (childpid == -1){cout << "\nERROR MAKING FORK";}
else if(childpid == 0){
	close(fd[0]);
	cout << "\nCHILD WRITES TO PIPE";
	write(fd[1], string, sizeof(string));
	cout <<"\nWRITE SUCCESSFULL";
	exit(0);}
else {close(fd[1]);
	cout << "\nParent Reading from pipe";
	read(fd[0], readbuffer, sizeof(readbuffer));
	cout << "RECEIVED STRING IS: " << readbuffer << endl;}


return 0;}
