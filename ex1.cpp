#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/signal.h>
#include<sys/wait.h>
#include <string.h>

using namespace std;

void handler_sig(int signum){
	//cout << signum << endl;
    if(signum == SIGCONT){
        //signal(SIGCONT,handler_sig);
        cout << "Child with pid " << getpid() << " is executing!" << endl;
        return;
   }
   return;
}

int main(int argc, char *argv[])
{
int num,i=0;
cout << "Give the number of SHILDREN: ";
cin >> num;

while(i<num){
         pid_t child;
         child=fork();

         if (child==0){
            signal(SIGCONT,handler_sig);
            cout << "Child with pid " << getpid() << " has been generated!" << endl;
            pause();
            cout << "Child with pid " << getpid() << " has finished!" << endl;
            exit(0);
         }

         else{
            usleep(500000);
            kill(child,SIGCONT);
            wait(NULL);
            i++;
         }
    }
}