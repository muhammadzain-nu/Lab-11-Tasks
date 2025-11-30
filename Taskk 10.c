#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 20

int isPalindrome(char word[]) {
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    char words[ROWS][COLS];
    int i;

    printf("Enter 5 words:\n");
    for (i = 0; i < ROWS; i++) {
        scanf("%s", words[i]);
    }

    printf("\n=== Palindrome Check ===\n");
    for (i = 0; i < ROWS; i++) {
        if (isPalindrome(words[i])) {
            printf("%s is Palindrome\n", words[i]);
        } else {
            printf("%s is Not Palindrome\n", words[i]);
        }
    }

    return 0;
}

