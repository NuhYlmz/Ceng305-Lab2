#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
volatile sig_atomic_t flag = 0;
void my_function(int sig){
  flag = 1;
}

int main(){

int counter=0;
int total=0;
int scannum;

char input[256];

while(1){  
signal(SIGINT, my_function);
printf("Enter a number: ");
fgets(input, sizeof(input), stdin);
scannum=atoi(input);
if(scannum==-1)
return 0;
counter++;
total=total+scannum;

if(flag){
printf("Inputs: %d , Average: %d\n",counter-1,(total/(counter-1)));
total=0;
counter=0;
flag = 0;
}
}
}  
//   gcc question1.c -0 question1
//   ./question1
//   Ctrl+c and press enter for calculate
//   -1 and press ENTER for exit.
