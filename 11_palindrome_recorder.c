#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 26

void find_palindrome_reorder(const char* str) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(str);
    
    // Count frequencies of each character
    for (int i = 0; i < len; i++) {
        freq[str[i] - 'A']++;
    }

    int odd_count = 0;
    char odd_char;
    
    // Check for the number of characters with odd frequency
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
            odd_char = i + 'A';
        }
    }

    if (odd_count > 1) {
        printf("NO SOLUTION\n");
        return;
    }

    // Create the palindrome
    char* half = (char*) malloc((len / 2 + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < MAX_CHAR; i++) {
        for (int j = 0; j < freq[i] / 2; j++) {
            half[index++] = i + 'A';
        }
    }
    half[index] = '\0';

    // Print the first half
    printf("%s", half);

    // Print the middle character if it exists
    if (odd_count == 1) {
        printf("%c", odd_char);
    }

    // Print the reverse of the first half
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", half[i]);
    }

    printf("\n");
    free(half);
}

int main() {
    char str[1000000];
    scanf("%1000000s", str);

    find_palindrome_reorder(str);

    return 0;
}
