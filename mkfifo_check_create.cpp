#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(){
//char * pipe_1 = "/tmp/myfifo";
//char * pipe_2 = "/tmp/myfifo";

int f1, f2;
f1 = mkfifo(pipe_1, 0666);
if(f1<0){cout << "PIPE 1 NOT CREATED!!!";}
else {cout << "PIPE 1 CREATED";}
f2 = mkfifo(pipe_2, 0666);
if(f2<0){cout << "PIPE 2 NOT CREATED!!!";}
else {cout << "PIPE 2 CREATED";}


return 0;}
