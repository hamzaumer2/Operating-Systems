#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


//HAMZA UMER
//LAB 6

using namespace std;
int main(){
int x;
cout << "Enter Option: ";
cin>>x;
switch(x){
case 1:{
pid_t childpid = fork();
	if ( childpid == 0){
	cout << "Child Process with PID: " << getpid();
	cout << "Next Statement will Run execv and ls will run";
	char* argv[]={"ls","-l", "/usr",NULL};
	execv("/bin/ls",argv);
	cout<< "Exec Failed"; 
		}
	else if (childpid>0){
	wait(NULL);
	cout << "Parent Process with PID: " << getpid();
		}
break;
}

case 2:{
pid_t childpid = fork();
        if ( childpid == 0){
        cout << "Child Process with PID: " << getpid();
        cout << "Next Statement will Run execv and ls will run";
        execl("/bin/ls","ls","-l","/usr",NULL); 
        cout<< "Exec Failed"; 
                }
        else if (childpid>0){
        wait(NULL);
        cout << "Parent Process with PID: " << getpid();
                }
break;
}


case 3:{
pid_t childpid = fork();
        if ( childpid == 0){
        cout << "Child Process with PID: " << getpid();
        cout << "Next Statement will Run execv and ls will run";
        execlp("/bin/date","date", NULL);
        cout<< "Exec Failed";
                }
        else if (childpid>0){
        wait(NULL);
        cout << "Parent Process with PID: " << getpid();
                }
break;
}

case 4:{
pid_t childpid = fork();
        if ( childpid == 0){
        cout << "Child Process with PID: " << getpid();
        cout << "Next Statement will Run execv and ls will run";
        execl("/bin/man","man",NULL); 
	cout<< "Exec Failed";
                }
        else if (childpid>0){
        wait(NULL);
        cout << "Parent Process with PID: " << getpid();
                }
break;
}

case 5:{

cout << "Exit";
	exit(0);
break;
	}

default:{
cout << "INVALID OPTION";
	return 0;
break;
	}

}

}
