#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int compare(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    ll *weights = (ll *)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &weights[i]);
    }

    // Sort the array of weights
    qsort(weights, n, sizeof(ll), compare);

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            left++;  // They can share a gondola
        }
        right--;  // The heaviest child takes the gondola
        gondolas++;
    }

    printf("%d\n", gondolas);

    free(weights);
    return 0;
}
