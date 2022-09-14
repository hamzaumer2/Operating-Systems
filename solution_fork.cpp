
#include<iomanip>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
    int A=0;
    int a=6;
    int b=6;
    int c=2;
    A=a*b;
    int status=A;
    int status1;
    pid_t id=fork();
    if(id==0)
    {
        A=A+(++a);
        status=A;
        pid_t id1=fork();
        if(id1==0)
        {
            A=A+(a-c);
            status=A;
            exit(status);
        }
        else 
        {
            pid_t Wait=wait(&status);
            status=status/255;   //dividing by 255 to get original value in status
            int status2=status;
            exit(status2);
        }
    }
    else 
    {
        pid_t w=wait(&status1);
        cout<<status1/255;
    }
    return 0;
}