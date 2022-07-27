//HAMZA UMER
// OPERATING SYSTEMS ASSIGNMENT 2
//QUESTION 4


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


int main(){
pid_t a,b,c,d,e,f,g,h,i,j;
int a_id, a2_id, b_id, b2_id, c_id, c2_id, d_id, d2_id, e_id, e2_id, f_id, f2_id, g_id, g2_id, h_id, h2_id, i_id, i2_id, j_id, j2_id;

a = fork();//making fork
a_id = getpid(), a2_id = getppid();//Process ID and Parent ID
wait(NULL);
if (a == -1){printf("\nNO FORK CREATED");}
else if (a == 0){//-------------------------------------INSIDE PROCESS A PARENT----------------------------------------------------------

b = fork();//FORK TO B
b_id = getpid(), b2_id = getppid();
wait(NULL);
c = fork();//FORK TO C
c_id = getpid(), c2_id = getppid();
wait(NULL);
d = fork();// FORK TO D
d_id = getpid(), d2_id = getppid();
wait(NULL);


if(b == -1 || c == -1 || d == -1){printf("\nNO FORK CREATED");}
//wait(NULL);

else if (b == 0 && c > 0 && d > 0){//----------------------------INSIDE B PROCESS---------------------------------------------------------
	e = fork();//FORK TO E
	e_id = getpid(), e2_id = getppid();
	wait(NULL);
	if(e == -1){printf("\nNO FORK CREATED");}
	else if (e == 0){//--------------------------------------INSIDE E PROCESS---------------------------------------------------------
		i = fork();// FORK TO I
		i_id = getpid(), i2_id = getppid();
		wait(NULL);
		j = fork();//FORK TO J
		j_id = getpid(), j2_id = getppid();
		wait(NULL);
		if(i == -1 || j == -1){printf("\nNO FORK CREATED");}
		else if (i == 0 && j > 0){printf("\nPROCESS I\t\t\t\t\t\tPID is: %d\t\tPPID is: %d", i_id, i2_id);}//---------INSIDE I PROCESS-----------
		else if (i > 0 && j == 0){printf("\nPROCESS J\t\t\t\t\t\tPID is: %d\t\tPPID is: %d", j_id, j2_id);}//---------INSIDE J PROCESS-----------
		else if(i > 0 && j > 0){printf("\n-----------");
					printf("\nPROCESS E, CHILDREN HERE ARE: I, J\t\t\tPID is: %d\t\tPPID is: %d\n", e_id, e2_id);
					printf("==================================");}

		}
	else if (e > 0){printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf("\nPROCESS B, CHILDREN HERE ARE: E\t\t\t\tPID is: %d\t\tPPID is:%d\n",b_id, b2_id);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
				}
//wait(NULL);
else if (b > 0 && c == 0 && d > 0){//----------------------------------INSIDE C PROCESS-------------------------------------------------
	f = fork();//FORK TO F
 	f_id = getpid(), f2_id = getppid();
	wait(NULL);
	g = fork();//FORK TO G
	g_id = getpid(), g2_id = getppid();
	wait(NULL);
	if (f == -1 || g == -1){printf("\nERROR MAKING FORK");}
	else if (f == 0 && g > 0){//-----------------------------------INSIDE F PROCESS-------------------------------------------------
		h = fork();//FORK TO H
		h_id = getpid(), h2_id = getppid();
		wait(NULL);
		if (h == -1){printf("\nERROR MAKING FORK");}
		else if (h == 0){printf("\nPROCESS H\t\t\t\t\t\tPID is: %d\t\tPPID is:%d", h_id, h2_id);}//----------------------------INSIDE F PROCESS-------------------------
		else if (h > 0){printf("\n-----------");
				printf("\nPROCESS F. CHILDREN HERE ARE: H\t\t\t\tPID is: %d\t\tPPID is:%d\n", f_id, f2_id);
				printf("=================================");}



		}
	else if (f > 0 && g == 0){printf("\nPROCESS G\t\t\t\t\t\tPID is: %d\t\tPPID is:%d", g_id, g2_id);}//-----------------------INSIDE G PROCESS------------------------------
	else if (f > 0 && g > 0){printf("\n-----------");
				printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\nPROCESS C, CHILDREN HERE ARE: F, G\t\t\tPID is: %d\t\tPPID is: %d\n", c_id, c2_id);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}
//wait(NULL);
else if (b > 0 && c > 0 && d == 0){	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");//----------------------INSIDE D PROCESS------------------------------
					printf("\nPROCESS D\t\t\t\t\t\tPID is: %d\t\tPPID is: %d", d_id, d2_id);
					printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					}
//wait(NULL);
else if (b > 0 && c > 0 && d > 0){
					printf("\n****************************************************************************************************");
					printf("\nPARENT PROCESS A, CHILDREN HERE ARE: B,C,D\t\tPID is: %d\t\tPPID is: %d\n", a_id, a2_id);
					printf("****************************************************************************************************\n");
					}
wait(NULL);
}
return 0;
}
