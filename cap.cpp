//HAMZA UMER
// BSCS - 4-B
// OS LAB  ASSIGNMENT 2 QUESTION 5

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *arcv[]){

char output[256];


for (int i = 0 ; i < argc ; i++){
output[i] = toupper(arcv[i]);
}
cout << "Capitalise is: ";
for (int i = 0 ; i < argc ; i++){
cout << output[i];
}

return 0;}
