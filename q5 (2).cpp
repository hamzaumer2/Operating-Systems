//HAMZA UMER
// BSCS - 4-B
// OS LAB  ASSIGNMENT 2 QUESTION 5

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
using namespace std;
int main()
{
	//string str1, str2;
    char input[256];
    int len, inc, sor, cap;
    cout << "Enter String: ";
    cin>>input;
    len = fork();
    if (len == 0)
    {
        inc = fork();
        if (inc == 0)
        {
            sor = fork();
            if (sor == 0)
            {
                cap = fork();
                if (cap == 0)
                {

                    sleep(4);
                    execl("~/Question/cap.o", input, NULL);
				//string cap1;
				//cap1 = st1;

				//for (int i = 0 ; i < cap1.length() ; i++){
				//cap1[i] = toupper(cap1[i]);
				//}



                }
                else if (cap > 0)
                {

                    sleep(3);
                    execl("~/Question/sor.o", input, NULL);
				//string str;
				//str = st1;
				//sort(str.begin(),str.end());
                }
                else
                {

                }
            }
            else if (sor > 0)
            {
                sleep(2);
                execl("~/Question/inc.o", input, NULL);

			//string add2;
			//add2 = st1;

			//for (int i = 0 ; i < add2.length() ; i++){
			//add2[i] = int(add2[i])+2;
			//}
            }
            else
            {

            }
        }
        else if (inc > 0)
        {

            sleep(1);
            execl("~/Question/len.o", input, NULL);
		//cout << st1.length();
        }
        else
        {

        }
    }
    else if (len > 0)
    {
	//str2 = str1;

        sleep(0);
        execl("~/Question/rev.o", input, NULL);
	//reverse(str2.begin(),str2.end());
	//cout << str2;
    }
    else
    {
    }
}
