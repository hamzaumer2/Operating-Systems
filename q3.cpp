//HAMZA UMER
// BSCS - 4 - B
// OPERATING SYSTEMS ASSIGNMENT 2
//QUESTION 3

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;


int main(){	//INT MAIN START
int p1,p2,p3,p4;
pid_t forking1; // USING THIS TRICK AS 'int p*' and 'pid_t *' dont work together
p1 = forking1;
p1 = fork();
//CALL FORK FOR P1
if (p1 == -1){
cout << "ERROR";
return 0;
}
else if (p1 == 0){	//FIRST CHILD PROCESS
cout << endl;
cout << "INSIDE P1" << endl;
//CALL FORK FOR P2
//IF P2 is '0' THEN PRINT getpid() and getppid()
pid_t forking2;
p2 = forking2;
p2 = fork();
	if (p2 == 0){		//SECOND CHILD PROCESS
	cout << endl;
	cout << "INSIDE P2" << endl;
	cout << "CHILD ID IS: " << getpid() << endl;
	cout << "PARENT ID IS: " << getppid() << endl;
	//CALL FORK FOR P3
	pid_t forking3;
	p3 = forking3;
	p3 = fork();
		if (p3 == -1){
		cout << "ERROR";
		return 0;
		}
		else if (p3 == 0){	//THIRD CHILD PROCESS
		cout << endl;
		cout << "INSIDE P3" << endl;
		cout << "CHILD ID IS: " << getpid() << endl;
		cout << "PARENT ID IS: " << getppid() << endl;
		//CALL FORK FOR P4
		pid_t forking4;
		p4 = forking4;
		p4 = fork();
			if (p4 == 0){	//FOURTH CHILD PROCESS
			cout << endl;
			cout << "INSIDE P4" << endl;
			cout << "CHILD ID IS: " << getpid() << endl;
			cout << "PARENT ID IS: " << getppid() << endl;

				}//FOURTH CHILD PROCESS END
			}//THIRD CHILD PROCESS END
		}//SECOND CHILD PROCESS END
	}//FIRST CHILD PROCESS END
return 0;
}//INT MAIN END
