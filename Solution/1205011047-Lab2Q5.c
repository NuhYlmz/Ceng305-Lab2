#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include<time.h>
void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}
volatile sig_atomic_t counter=0;
volatile sig_atomic_t i=0;
volatile sig_atomic_t flag = 0; //changed
void my_function(int sig){
flag = 1;
}

int main(){ //main start
srand(time(NULL));
void printnum(){
printf("%d\n",rand()%10);
counter++;
}

void printlet(){
printf("%c\n",(rand()%(123-97))+97);
counter++;
}

void printXX(){
if(i==1)
printnum();
else
printlet();
}

 
i=rand()%2;
signal(SIGINT, my_function);
flag=1;
while(1){ //while start
if(flag){ //flag start
if(i==1){

i=0;
}
else{
i=1;
}
flag=0;
}//flag finish
if(counter==15)
return 0;
printXX();
delay(1000000);
} //while finish
} //main finish

