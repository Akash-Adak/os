#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void signalHandler(int sin){
printf("signal is =%d\n",sin);
exit(sin);
}
int main(){
signal(SIGINT,signalHandler);
while(1){
printf("hello Akash !");
}
return 0;
}

