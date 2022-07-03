#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main()
{

    int n1 = fork(), n2 = fork();

    if (n1 > 0 && n2 > 0) {
        cout << "\nParent Process";

        cout << "\tID of Parent is: "<< getpid();
    }
    else if (n1 == 0 && n2 > 0)
    {
        cout << "\nFirst Child";
        cout << "\tID of First Child is: " <<  getpid();
    }
    else if (n1 > 0 && n2 == 0)
    {
        cout << "\nSecond Child";
        cout << "\tID of Second Child is: " << getpid() << endl;
    }
    return 0;
}
