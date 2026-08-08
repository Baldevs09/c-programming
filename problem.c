#include<stdio.h>
int main (){
	int a,b;
	printf("enter a number:");
	scanf("%d",&a);
	printf("enter a number:");
	scanf("%d",&b);
	if (a>b){
		printf("a is largest%d",a);
	}
	else if  (b>a){
		printf("b islargest %d",b);
	}
	else{
		printf("both the numbers are eaual");
	}



	return 0;
}
