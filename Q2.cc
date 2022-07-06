#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
using namespace std;

int main (){
	char arr[3];
	cout << "\nEnter fist 3 letters of your name. Pressing Enter or Space after Each";
	for (int i = 0 ; i < 3 ; i++){
	cin>>arr[i];}


pid_t n1 = fork();
	if (n1>1){
		cout << "\nParent Process ";
		cout << "\tFirst Letter is: " << arr[0];

		//wait(NULL);
	}
	else if (n1 ==0){
n1 = fork();
if (n1>1){
cout << "\nChild Process" << "\nSecond Letter is: " << arr[1];
}

else {
cout << "\nGrand Child Process" << "\nThird Letter is: " << arr[2];

}
}
}
