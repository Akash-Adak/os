#include<stdio.h>
int fact(int n){
	if(n==0 || n==1) return 1;
	return fact(n-1)*n;
}
int main(){
	int n;
	printf("enter no:");
	scanf("%d",&n);
	int res=fact(n);
	printf("factorial of %d is :%d",n,res);
	return 0;
}
