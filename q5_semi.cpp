//HAMZA UMER
// BSCS - 4 - B
// OPERATING SYSTEMS ASSIGNMENT 2
//QUESTION 5

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;


int main(){//INT MAIN START

string st1;
cout << "ENTER STRING: ";
cin>>st1;

int p1,p2,p3,p4,p5;
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

string str2;
str2 = st1;

reverse(str2.begin(),str2.end());

cout << "STRING REVERSED IS: " << str2 << endl;


//--------------------------------------------------------------------------------------------


//CALL FORK FOR P2
//IF P2 is '0' THEN PRINT getpid() and getppid()
pid_t forking2;
p2 = forking2;
p2 = fork();
	if (p2 == 0){		//SECOND CHILD PROCESS
	cout << endl;
	cout << "LENGTH OF STRING IS: " << st1.length() <<endl;

//---------------------------------------------------------------------------------------------
//	cout << "CHILD ID IS: " << getpid() << endl;
//	cout << "PARENT ID IS: " << getppid() << endl;
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




string add2;
add2 = st1;

for (int i = 0 ; i < add2.length() ; i++){
add2[i] = int(add2[i])+2;
}



		cout << "ADDING 2 TO ASCII OF STRING's EACH CHARACTER MAKES: " << add2 << endl;













//-----------------------------------------------------------------------------------------------
//		cout << "CHILD ID IS: " << getpid() << endl;
//		cout << "PARENT ID IS: " << getppid() << endl;
		//CALL FORK FOR P4
		pid_t forking4;
		p4 = forking4;
		p4 = fork();
			if (p4 == 0){	//FOURTH CHILD PROCESS
			cout << endl;



//int len = st1.length();
//char temp;
//string str;
//str = st1;
//for (int i = 0; i < len; i++){
//
//    for (int j = 0; j < len - 1; j++){
//      if (str[j] > str[j + 1]){
//
//        temp = str[j];
//        str[j] = str[j + 1];
//        str[j + 1] = temp;
//      }
//    }
//  }

string str;
str = st1;
sort(str.begin(),str.end());

cout << "SORITNG THE STRING ALPHABETICALLY NAMES: " << str << endl;











//------------------------------------------------------------------------------------------------
//			cout << "CHILD ID IS: " << getpid() << endl;
//			cout << "PARENT ID IS: " << getppid() << endl;
			//CALL FORK FOR P5
				pid_t forking5;
				p5 = forking5;
				p5 = fork();
				if (p5 == -1){cout << "ERROR";}
				else if (p5 == 0){//FIFTH CHILD PROCESS
				cout << endl;
string cap1;
cap1 = st1;

for (int i = 0 ; i < cap1.length() ; i++){
cap1[i] = toupper(cap1[i]);
}


cout << "CAPITALISING EVERY CHARACTER OF STRING MAKES: " << cap1 << endl;



//------------------------------------------------------------------------------------------------
//                        	cout << "CHILD ID IS: " << getpid() << endl;
//                      	cout << "PARENT ID IS: " << getppid() << endl;


					}//FIFTH CHILD PROCESS END

				}//FOURTH CHILD PROCESS END
			}//THIRD CHILD PROCESS END
		}//SECOND CHILD PROCESS END
	}//FIRST CHILD PROCESS END
return 0;
}//INT MAIN END
