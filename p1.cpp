#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
using namespace std;
int  main()
{
char m[256]="Hllo its m";
char str[256]="hllo";
int fifowrite=open("fifoa",O_WRONLY);
int fiforead=open("fifob",O_RDONLY);
int choice;
cin>>choice;
cout<<"ali";
if(choice==1)
{
while(strcmp(m,"abort")!=0)
{
cout<<"ENTER TEXT"<<endl;
cin>>m;
write(fifowrite,m,sizeof(m));
cout<<m<<endl;

}
close (fifowrite);

}

else if(choice=2);
{
cout<<"reading from second process"<<endl;
while(strcmp(str,"abort")!=0)
{
read(fiforead,str,sizeof(str));
cout<<str<<endl;
}
close(fiforead);
}
return 0;

}
