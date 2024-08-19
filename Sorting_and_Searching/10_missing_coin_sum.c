#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int compare(const void *a, const void *b) {
    return *(ll*)a > *(ll*)b ? 1 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    ll arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(ll), compare);

    ll current_sum = 1;  // The smallest sum we are trying to form

    for (int i = 0; i < n; i++) {
        if (arr[i] > current_sum) {
            // If the current coin is greater than the sum we can't form, print the answer
            break;
        }
        current_sum += arr[i];  // Otherwise, we can now form this sum and more
    }

    printf("%lld\n", current_sum);

    return 0;
}
