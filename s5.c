#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void myThread(){
printf("hello from thread \n");
return NULL;
}

int main(){
pthread_t t;
pthread_create(&t,NULL,myThread,NULL);
pthread_join(t,NULL);
printf("main thread finished\n");
return 0;
}
