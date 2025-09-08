#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int am;
void alm(int sig){
am=1;
}
int main(){
int pid;
am=0;
pid=fork();

if(pid==0){
sleep(5);
kill(getppid(),SIGALRM);;
exit(0);
}else{
signal(SIGALRM,alm);
pause();
if(am){
printf("signal received and parents goes off\n");
exit(0);
}
}
return 0;
}
void sendsig(){
printf("wrong calculation !!!!!!!!!\n");
exit(0);
}
