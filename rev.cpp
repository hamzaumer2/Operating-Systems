
//HAMZA UMER
// BSCS - 4-B
// OS LAB  ASSIGNMENT 2 QUESTION 5

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <cstring>
#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;

int main(string argv, char arcv[]) {

	char temp[256];

for(int i = 0 ; i < argv/2 ; i++){
	temp[i] = argv[i];
	arr[i] = argv[argv-i-1];
	argv[argv-i-1] = temp[i];
}
	cout << "REVERSED ARRAY IS: ";
	for (int i = 0 ; i < argv ; i++){
	cout << argv[i];}
    return 0;
}
