#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
// Driver code
int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n;
    n = fork();
 
    if (n > 0) {
cout << "\nChild Process: ";
cout << "\nPID HERE IS: " << getpid();
cout << "\nPPID HERE IS: " << getppid();
cout << "\nNUMBERS PRINTED HERE ARE: ";
        for (int i = 0; i < 5; i++) {
        
        cout << a[i] << ", ";
    }
}
 
    else {
wait(NULL);
cout << "\nParent Process: ";
cout << "\nPID HERE IS: " << getpid();
cout << "\nPPID HERE IS: " << getppid();
cout << "\nNUMBERS PRINTED HERE ARE: ";
        for (int i = 5; i < 10; i++) {
     
        cout << a[i] << ", ";
    }}
return 0;
}
//else {
//cout << "\nNO CHILD PROCESS CREATED!!!";}
//    return 0;
//}
