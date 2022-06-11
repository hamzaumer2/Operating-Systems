//HAMZA UMER FAROOQ
//200789 - BSCS-4-B

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(){
int pipe1[2], pipe2[2];

if(pipe(pipe1) == -1 || pipe(pipe2) == -1){
cout << "ERROR";
}

int id = fork();

if(id==0){
char filename[50];
char buffer[50];
read(pipe1[0], filename, 30);
cout << "Enter Text: ";
cin.getline(buffer,50);
write(pipe2[1],buffer,sizeof(buffer));
}
else{
char filename[50];
char buffer[50];
cout << "Enter Filename: ";
cin>>filename;
write(pipe1[1],filename,sizeof(filename));
read(pipe2[0],buffer,50);
cout << buffer << endl;

}


return 0;
}
