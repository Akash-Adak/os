#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void myThread1(){
printf("hello from thread 1 \n");
return NULL;
}

void myThread2(){
printf("hello from thread 2\n");
return NULL;
}


int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,myThread1,NULL);
pthread_create(&t2,NULL,myThread2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("main thread finished\n");
return 0;
}
