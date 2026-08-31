// //----------------------------------------------------------ARRAY-----------------------------------------------------------------------
// #include<stdio.h>
// int main(){
// 	float price[3];
// 	printf("enter your item price:");
// 	scanf("%f",&price[0]);
// 	printf("enter your item price:");
// 	scanf("%f",&price[1]);
// 	printf("enter your item price:");
// 	scanf("%f",&price[2]);
// 	printf("total price:%f",price[0]+(0.18*price[0]));
// 	printf("total price:%f",price[1]+(0.18*price[1]));
// 	printf("total price:%f",price[2]+(0.18*price[2]));
// 	return 0;
// }
// #include <stdio.h>

// int main() {
//     int num;

//     printf("Enter a number: ");
//     scanf("%d", &num);

//     if (num % 2 == 0) {
//         printf("%d is Even\n", num);
//     } else {
//         printf("%d is Odd\n", num);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int a, b, c;

//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &a, &b, &c);

//     if (a >= b && a >= c) {
//         printf("%d is the largest", a);
//     }
//     else if (b >= a && b >= c) {
//         printf("%d is the largest", b);
//     }
//     else {
//         printf("%d is the largest", c);
//     }

//     return 0;
// // }
// #include <stdio.h>

// int main() {
//     int n, i, isPrime = 1;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     if (n <= 1) {
//         isPrime = 0;
//     } else {
//         for (i = 2; i <= n / 2; i++) {
//             if (n % i == 0) {
//                 isPrime = 0;
//                 break;
//             }
//         }
//     }

//     if (isPrime)
//         printf("%d is a prime number", n);
//     else
//         printf("%d is not a prime number", n);

//     return 0;
// // }
// #include <stdio.h>

// int main() {
//     int n, reverse = 0, rem;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     while (n != 0) {
//         rem = n % 10;
//         reverse = reverse * 10 + rem;
//         n = n / 10;
//     }

//     printf("Reverse = %d", reverse);

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int n, original, reverse = 0, rem;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     original = n;

//     while (n != 0) {
//         rem = n % 10;
//         reverse = reverse * 10 + rem;
//         n = n / 10;
//     }

//     if (original == reverse) {
//         printf("%d is a palindrome", original);
//     } else {
//         printf("%d is not a palindrome", original);
//     }

//     return 0;
// }
#include <stdio.h>

int main() {
    int n, original, reverse = 0, rem;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    while (n != 0) {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n = n / 10;
    }

    if (original == reverse) {
        printf("%d is a palindrome", original);
    } else {
        printf("%d is not a palindrome", original);
    }

    return 0;
}
