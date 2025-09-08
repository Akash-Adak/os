#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sendsig();
int main(){
signal(SIGINT,sendsig);
while(1){
printf("hello akash !\n");
sleep(2);
}
return 0;
}
void sendsig(){
printf("Received the signal :::::>> \n");
signal(SIGINT,SIG_DFL);
}


