#include <iostream>
#include <unistd.h>
using namespace std;
 
// Driver code
int main()
{
cout << "\nEnter Array Size: ";
cin>>size;
    int a[100];
    int sumOdd = 0, sumEven = 0, n, i;
    n = fork();
 
    // Checking if n is not 0
    if (n > 0) {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 == 0)
                sumEven = sumEven + a[i];
        }
        cout << "Parent process \n";
        cout << "Sum of even no. is " << sumEven << endl;
    }
 
    // If n is 0 i.e. we are in child process
    else {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 != 0)
                sumOdd = sumOdd + a[i];
        }
        cout << "Child process \n";
        cout << "\nSum of odd no. is " << sumOdd << endl;
    }
    return 0;
}
