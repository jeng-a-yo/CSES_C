#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long int ll;

int compare(const void *a, const void *b) {
    ll arg1 = *(const ll *)a;
    ll arg2 = *(const ll *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int main(void) {
    int n;
    scanf("%d", &n);

    ll lengths[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &lengths[i]);
    }

    qsort(lengths, n, sizeof(ll), compare);

    // Median is the middle element in the sorted array
    ll median = lengths[n / 2];

    ll min_diff = 0;
    for (int i = 0; i < n; i++) {
        min_diff += llabs(lengths[i] - median);
    }

    printf("%lld\n", min_diff);

    return 0;
}
