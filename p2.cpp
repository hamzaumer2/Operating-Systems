#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
using namespace std;
int main()
{
char str[256]="hllo its m";
char m[256]="hllo";
int fifowr=open("fifob",O_WRONLY);
int fifo_read=open("fifoa",O_RDONLY);
int choice;

cin>>choice;
if(choice==0)
{
while(strcmp(str,"abort")!=0)
{
read(fifo_read,str,sizeof(str));
cout<<str<<endl;
}
close(fifo_read);
}
else if(choice==1)
{
cout<<"writing data"<<endl;
while(strcmp(m,"abort")!=0)
{
cout<<"ENTER TEXT"<<endl;
cin>>m;
write(fifowr,m,sizeof(m));
cout<<m<<endl;

}
}
close(fifowr);}
