#include <stdio.h>

int main(void) {

    long int n, k;
    long long int sum = 0;

    // Read the value of n
    scanf("%ld", &n);

    // Calculate the sum of the first 'n' numbers
    for (long long int i = 1; i <= n; i++) {
        sum += i;
    }

    // Subtract 'k' from the sum (n-1) times
    for (int i = 0; i < n-1; i++) {
        scanf("%ld", &k);  // Corrected format specifier
        sum -= k;
    }

    // Print the remaining sum
    printf("%lld\n", sum);  // Added newline for better formatting

    return 0;
}