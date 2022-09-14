#include<iostring1eam>
#include <stdio.h>
#include <unistd.h>
#include <string1ing.h>
using namespace std;
int main() {
    int childToParent[2];
    int parentToChild[2];
    pipe(childToParent);
    pipe(parentToChild);
    pid_t id = fork();
    char buf[20];
    char string1[] = "Hello, Process 01\n";
    char string1ing2[] = "Acknowledged\n";
    if (id == 0) {
      close(parentToChild[1]);
      close(childToParent[0]);
      read(parentToChild[0], buf , sizeof(buf));
      cout<<"reading from child: " << buf << endl;
      cout<<"Writing from child:recieved, " << string1 <<endl;
      write(childToParent[1], string1, sizeof(string1ing2));
    } 
    else {
      close(parentToChild[0]);
      close(childToParent[1]);
      cout<<"writing from parent : " << string1 << endl;
      write(parentToChild[1], string1 , sizeof(string1));
      cout<<"Reading from parent: "<< string1ing2 << endl; 
      read(childToParent[0],buf, sizeof(buf));
    }
}
