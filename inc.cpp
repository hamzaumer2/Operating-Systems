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

	for (int i = 0 ; i < argv.length() ; i++){
	arcv[i] = int(arcv[i])+2;}


    cout << "ASCII value of %c = %d" << arcv;

    return 0;
}
