// Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

// Input:
// - Single integer n

// Output:
// - Print the n-th Fibonacci number

#include <stdio.h>
int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    printf("Enter the nth fibonacci number: ");
    scanf("%d",&n);
    printf("%d ",fib(n));
    return 0;
}