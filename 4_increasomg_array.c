#include <stdio.h>

int main(void) {
    long long int n;
    scanf("%lld", &n);

    long long int list[200000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &list[i]);
    }

    long long int moves = 0;  // Initialize moves to 0
    for (int i = 1; i < n; i++) {  // Start from the second element
        if (list[i] < list[i - 1]) {
            moves += list[i - 1] - list[i];  // Calculate the difference and add to moves
            list[i] = list[i - 1];  // Update the current element
        }
    }

    printf("%lld\n", moves);

    return 0;
}