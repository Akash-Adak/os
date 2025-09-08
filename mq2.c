#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int mgid;
	for(int i=0;i<5;i++){
	mgid=msgget((key_t)i,IPC_CREAT);
	if(mgid <0){
	printf("message queue creation faild");
	exit(0);
	}
printf(" %d message queue created with id : %d\n",i+1,mgid);
}
return 0;
}
