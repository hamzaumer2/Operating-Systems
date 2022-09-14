//HAMZA UMER
// BSCS - 4-B
// OS LAB  ASSIGNMENT 2 QUESTION 5

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char *arcv[]){


char temp;
for(int i=0;i<argc;i++)
    {
        for(int j=0;j<argc;j++)
        {
            if(arcv[i]>arcv[j])
            {
                temp=arcv[i];
                arcv[i]=arcv[j];
                arcv[j]=temp;
            }
        }
    }



return 0;}
