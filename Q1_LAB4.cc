//HAMZA UMER FAROOQ - 200789

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
// Driver code
int main()
{
    int check;
cout << "\nINPUT NUMBER: ";
cin>>check;
    int n;
    n = fork();
 
    if (n > 0 && check%2 != 0 ) {
cout << "\nTHE NUMBER WILL BE IN Child Process!! ";
exit(0);
return 0;
}
 
    else {

cout << "\nTHE NUMBER WILL BE IN Parent Process!! ";
wait(NULL);
exit(0);
return 0;
}
return 0;
}
//else {
//cout << "\nNO CHILD PROCESS CREATED!!!";}
//    return 0;
//}


