#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 26

// Function to calculate factorial
long int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to swap two characters
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap two strings
void swap_strings(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations
void permute(char* str, int l, int r, char** strings, long int* index) {
    if (l == r) {
        strcpy(strings[*index], str);
        (*index)++;
    } else {
        int isDuplicate[256] = {0};  // Array to keep track of duplicates
        for (int i = l; i <= r; i++) {
            if (isDuplicate[(int)str[i]] == 0) {
                isDuplicate[(int)str[i]] = 1;
                swap((str + l), (str + i));
                permute(str, l + 1, r, strings, index);
                swap((str + l), (str + i));  // Backtrack
            }
        }
    }
}

// Function to partition the array for quicksort
int partition(char** arr, int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap_strings(&arr[i], &arr[j]);
        }
    }
    swap_strings(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(char** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(void) {
    char str[8];
    scanf("%8s", str);

    int len = strlen(str);
    long count = factorial(len);

    // Initializing frequency array to zeros
    int freq[MAX_LENGTH] = {0};
    // Calculate the frequency of characters
    for (int i = 0; i < len; i++) freq[str[i] - 'a']++;
    // Count the quantity of the strings
    for (int i = 0; i < MAX_LENGTH; i++) count /= factorial(freq[i]);
    printf("%ld\n", count);

    // Initialize the strings
    char** strings = (char**) malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) strings[i] = (char*) malloc((len + 1) * sizeof(char));

    // Generate permutations
    long int index = 0;
    permute(str, 0, len - 1, strings, &index);

    // Sort permutations using quicksort
    quicksort(strings, 0, count - 1);

    // Print permutations
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);

    return 0;
}
