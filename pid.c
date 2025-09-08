#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main(){

fork();
printf("child pid is =%d\n",getpid());
printf("parent pid is =%d\n",getppid());
return 0;
}
