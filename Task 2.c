#include <stdio.h>
#include <string.h>

void reverseStringRecursiveHelper(char* str, int start, int end) {
    
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseStringRecursiveHelper(str, start + 1, end - 1);
}


void reverseString(char* str) {
    if (str == NULL) {
        return;
    }
    int length = strlen(str);
    reverseStringRecursiveHelper(str, 0, length - 1);
}

int main() {
    char str[20];
    printf("\nEnter The string:");
    scanf("%[^\n]", str);
    getchar();
    printf("Original string 1: %s\n", str);
    reverseString(str);
    printf("Reversed string 1: %s\n", str);

    return 0;
    
}
