#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
using namespace std;

int main(){
int a,b,c,y;
char x;

cout << "\nEnter Name and Roll Number Pressing Enter/SPACE after each: ";
cin>>x>>y;
int n1 = fork();

if (n1 > 0) {
        cout << "\nParent Process";
        cout << "\nCharacter of Name: " << x;
	cout << "\n\nID of Parent is: " << getpid();

wait(NULL);
}

else if (n1 == 0)
        {
        cout << "\nChild Process";
	cout << "\nRoll Number: " << y << endl; 
        cout << "\n\nID of Child is: " <<  getpid(); 
wait(NULL);
}

return 0;
}
