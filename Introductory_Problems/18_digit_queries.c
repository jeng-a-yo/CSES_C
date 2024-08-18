#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    long long int* nums = (long long int*) malloc(n * sizeof(long long int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
        long long int k = nums[i];

        long long digits = 1, count = 9, start = 1;

        // Determine which range the k-th digit falls into
        while (k > digits * count) {
            k -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        // Determine the exact number
        start += (k - 1) / digits;
        char num_str[20];
        sprintf(num_str, "%lld", start);

        // Output the k-th digit
        printf("%c\n", num_str[(k - 1) % digits]);

    }

    

    return 0;
}
