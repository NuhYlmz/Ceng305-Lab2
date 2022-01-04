#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include<time.h>
void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}
volatile sig_atomic_t i=0;
volatile sig_atomic_t flag = 0; //changed
void my_function(int sig){
flag = 1;
}

int inc_dec(int num){
if(i==1)
return num+10;
else
return num-10;
}

int main(){ //main start
srand(time(NULL)); 
i=rand()%2;
int number=(rand()%101)+100;
signal(SIGINT, my_function);
flag=1;
while(1){ //while start
if(flag){ //flag start
if(i==1){

printf("[Decreasing]\n");
i=0;
}
else{
printf("[Increasing]\n");
i=1;
}
flag=0;
}//flag finish

number=inc_dec(number);
printf("Variable: %d\n",number);
delay(1000000);
if(number<=100 || number >=200){
return 0;
}
} //while finish
} //main finish

