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
// #include <stdio.h>

// int main() {
//     int n, i;
//     long long factorial = 1;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     if (n < 0) {
//         printf("Factorial is not defined for negative numbers.");
//     } else {
//         for (i = 1; i <= n; i++) {
//             factorial = factorial * i;
//         }

//         printf("Factorial of %d = %lld", n, factorial);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int n, i;
//     int a = 0, b = 1, next;

//     printf("Enter the number of terms: ");
//     scanf("%d", &n);

//     printf("Fibonacci series: ");

//     for (i = 1; i <= n; i++) {
//         printf("%d ", a);

//         next = a + b;
//         a = b;
//         b = next;
//     }

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int arr[5];
//     int i;

//     printf("Enter 5 numbers:\n");

//     for (i = 0; i < 5; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("Array elements are:\n");

//     for (i = 0; i < 5; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// // }
// #include <stdio.h>

// int main() {
//     int arr[5];
//     int i, largest;

//     printf("Enter 5 numbers:\n");

//     for (i = 0; i < 5; i++) {
//         scanf("%d", &arr[i]);
//     }

//     largest = arr[0];

//     for (i = 1; i < 5; i++) {
//         if (arr[i] > largest) {
//             largest = arr[i];
//         }
//     }

//     printf("Largest number = %d", largest);

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int arr[5];
//     int i, largest, second;

//     printf("Enter 5 numbers:\n");

//     for (i = 0; i < 5; i++) {
//         scanf("%d", &arr[i]);
//     }

//     largest = arr[0];
//     second = arr[0];

//     for (i = 1; i < 5; i++) {
//         if (arr[i] > largest) {
//             second = largest;
//             largest = arr[i];
//         }
//         else if (arr[i] > second && arr[i] != largest) {
//             second = arr[i];
//         }
//     }

//     printf("Largest = %d\n", largest);
//     printf("Second largest = %d\n", second);

//     return 0;
// }
// #include <stdio.h>

// int main() {
//     int arr[10];
//     int i, even = 0, odd = 0;

//     printf("Enter 10 numbers:\n");

//     for (i = 0; i < 10; i++) {
//         scanf("%d", &arr[i]);
//     }

//     for (i = 0; i < 10; i++) {
//         if (arr[i] % 2 == 0) {
//             even++;
//         } else {
//             odd++;
//         }
//     }

//     printf("Even numbers = %d\n", even);
//     printf("Odd numbers = %d\n", odd);

//     return 0;
// }
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) {
        printf("%d is the largest number.\n", a);
    }
    else if (b >= a && b >= c) {
        printf("%d is the largest number.\n", b);
    }
    else {
        printf("%d is the largest number.\n", c);
    }

    return 0;
}
