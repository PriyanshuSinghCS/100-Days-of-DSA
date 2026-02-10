// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

#include <stdio.h>
#include <string.h>

int main(){
    char str[50];
    printf("Enter the string: ");
    gets(str);
    int x=strlen(str);
    int j=x-1;
    int check = 1;
    for(int i=0;i<x/2;i++){
        if(str[i]!=str[j]){
            check=0;
            break;
        }
        j--;
    }
    if(check==1){
        printf("It's a palindrome.");
    }
    else printf("No, it's not a palindrome.");
    return 0;
}