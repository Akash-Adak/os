#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void fpe_handler(int sin){
printf("current handler = %d ( can't divide by zero)\n ",sin);
exit(sin);
}
int main(){
signal(SIGFPE,fpe_handler);
int a,b,c=0;
printf("enter a:\n");
scanf("%d",&a);
printf("enter b :\n");
scanf("%d",&b);
c=a/b;
printf("ans is=%d\n",c);
return 0;
}


