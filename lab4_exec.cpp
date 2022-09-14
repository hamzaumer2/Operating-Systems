#include <stdio.h>
#include <stdlib.h>
#include<cstring>
#include<iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
using namespace std;
int main( void ) {
  string userinput;
  for (size_t i = 0; i < 15; i++) {
    cout<<"Enter one of following command: ls , date , ps , a.out , top , and Exit to exit .\n";
    cin>>userinput;
    if(userinput == "Exit")
    	exit(0);
    int pid = fork();
  	if ( pid == 0 ) {
        if(userinput == "ls"){
          execlp("ls","ls","/usr",NULL);
        }
        else if(userinput == "date"){
          execl("/bin/date", "date", 0, (char*) NULL);
        }
        else if(userinput == "forest"){
          execl("/bin/ps", "ps", "--forest", (char*) NULL);
        }
        else if(userinput == "top"){
          execlp("top","top",NULL);
        }
        else if (userinput == "a.out"){
          char *args[]={"./a.out",NULL};
          execv(args[0],args);
        }
        else{
          cout<<"invalid arguments\n";
        }
        printf("Execl failed") ;
  	}
    else {
        wait(NULL);
  	}

  }


	return 0;
}
