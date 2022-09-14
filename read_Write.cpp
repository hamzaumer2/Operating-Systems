#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(){
char buffer[20];
cout << "Enter String" << endl;
read(0, buffer, 20);
write(1, buffer, 20);

return 0;
	}
