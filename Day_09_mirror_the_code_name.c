// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

#include <stdio.h>
#include <string.h>
int main(){
    char str[50];
    printf("Enter the code:\n");
    gets(str);
    int x = strlen(str);
    int j=x-1;
    char temp;
    for(int i=0;i<x/2;i++){
        temp = str[j];
        str[j]=str[i];
        str[i]=temp;
        j--;
    }
    puts(str);
    return 0;
}