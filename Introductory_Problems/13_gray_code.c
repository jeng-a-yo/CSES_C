#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reflect and add prefix to the Gray code
char** reflect(char** gray_code, int size) {
    char** reflected_code = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        reflected_code[i] = (char*) malloc((strlen(gray_code[i]) + 1) * sizeof(char));
        strcpy(reflected_code[i], gray_code[size - 1 - i]);
    }
    return reflected_code;
}

char** generate_gray_code(int n) {

    int size = 1 << n; // 2^n
    char** gray_code = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        gray_code[i] = (char*) malloc((n + 1) * sizeof(char)); // n bits + null terminator
    }

    // Base case for 1-bit Gray code
    strcpy(gray_code[0], "0");
    strcpy(gray_code[1], "1");

// Generate Gray codes for n bits
    for (int i = 2; i <= n; i++) {
        int curr_size = 1 << (i - 1); // 2^(i-1)
        char** reflected_code = reflect(gray_code, curr_size);

        // Add '0' prefix to the original codes
        for (int j = 0; j < curr_size; j++) {
            char temp[n + 1];
            sprintf(temp, "0%s", gray_code[j]);
            strcpy(gray_code[j], temp);
        }

        // Add '1' prefix to the reflected codes
        for (int j = 0; j < curr_size; j++) {
            char temp[n + 1];
            sprintf(temp, "1%s", reflected_code[j]);
            strcpy(gray_code[curr_size + j], temp);
        }

        // Free memory allocated for reflected_code
        for (int j = 0; j < curr_size; j++) {
            free(reflected_code[j]);
        }
        free(reflected_code);
    }

    return gray_code;

}

int main(void) {

    int n;
    scanf("%d", &n);

    char** gray_code = generate_gray_code(n);
    int size = 1 << n;

    
    for (int i = 0; i < size; i++) {
        printf("%s\n", gray_code[i]);
        free(gray_code[i]); // Free each string
    }
    free(gray_code); // Free the array of strings

    return 0;
}