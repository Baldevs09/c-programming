#include<stdio.h>
int main(){
	int a,b,sum;
	printf("enter your number:");
	scanf("%d",&a);
	printf("enter your number:");
	scanf("%d",&b);
	sum=a+b;
	printf("%d",sum);
	return 0;

#include<stdio.h>
int main (){
	int a,b;
	printf("enter your number:");
	scanf("%d",&a);
	printf("enter your number");
	scanf("%d",&b);
	printf("sum of %d",a-b);

	return 0;
}

#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;}
