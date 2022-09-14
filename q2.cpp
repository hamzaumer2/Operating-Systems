#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
char mynum = '0';
int main(void){

int i;
pid_t fork_return;
static char buffer[10];
fork_return = fork();

if (fork_return == 0){

	strcpy(buffer, "CHILD");
	for (i = 0 ; i < 5 ; ++i){

	mynum = i + '0';
	cout << buffer << mynum << endl;
	}
return 0;
}
else if (fork_return > 0){

	strcpy(buffer, "PARENT");
	for (i = 0 ; i < 5 ; ++i){
	cout << buffer << mynum << endl;
}
return 0;
}
else {

cout << "ERROR";

}


}
