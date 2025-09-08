#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t pid;
pid=fork();
if(pid<0){
printf("process failed");
return -1;
}
else if(pid==0){
sleep(2);
printf("child process\n");
printf("PID =%d\n",getpid());
printf("parent id=%d\n",getppid());
}
else{
printf("parent process\n");
printf("PID =%d\n",getpid());
printf("child id=%d\n",pid);
printf("grand parent id =%d\n",getppid());
}
return 0;
}
