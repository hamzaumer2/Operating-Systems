//HAMZA UMER
//BSCS - 4 - B
//OS LAB MID EXAM
//QUESTION 2


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
int arr[10];
for(int i = 0 ; i < 10 ; i++){
cout << "ENTER VALUE NUMBER " << i+1 << ":   ";
cin>>arr[i];
}
pid_t childmake;
childmake = fork();
wait(NULL);
if(childmake == -1){cout << "\nCHILD NOT CREATED!!!";}

else if(childmake == 0){//CHILD PROCESS//////////////////////////
	int large = 0, small = 1;
	cout << "\nINSIDE CHILD PROCESS";
	cout << "\nCALCULATING MINIMUN AND MAXIMUM!!";

	for(int k = 0 ; k < 10 ; k++){
	if (large < arr[k]){large = arr[k];}
	if (small > arr[k]){small = arr[k];}
}
	cout << "\nLARGEST NUMBER IS: " << large;
	cout << "\nSMALLEST NUMBER IS: " << small;


}


else {	//PARENT PROCESS////////////////////////////////////////
	int sum = 0;
	float avg = 0;
	cout <<"\n\nINSIDE PARENT PROCESS";
	cout << "\nCALCULATING SUM AND AVERAGE!!";
	for(int j = 0 ; j < 10 ; j++){
	sum = sum + arr[j];
	}
	cout << "\nSUM IS: " << sum;
	avg = (float(sum)/10);
	cout << "\nAVERAGE IS: " << avg;

}



return 0;}


