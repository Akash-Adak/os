#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int mgid;
	mgid=msgget((key_t)12,IPC_CREAT);
	if(mgid <0){
	printf("message queue creation faild");
	exit(0);
	}
printf("message queue created with id : %d\n",mgid);
return 0;
}

