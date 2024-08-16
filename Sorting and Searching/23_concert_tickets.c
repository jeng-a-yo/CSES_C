#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int compare(const void *a, const void *b) {
    return (*(ll *)a > *(ll *)b) ? 1 : -1;
}

ll find_ticket(ll* prices, int* last_index, ll maximum) {
    int left = 0, right = *last_index, mid;
    ll result = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (prices[mid] <= maximum) {
            result = prices[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (result != -1) {
        // Shift the remaining elements to the left, effectively "removing" the used ticket
        for (int i = right; i < *last_index; i++) {
            prices[i] = prices[i + 1];
        }
        (*last_index)--;
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ll *prices = (ll*) malloc(n * sizeof(ll));
    ll *maximums = (ll*) malloc(m * sizeof(ll));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &prices[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%lld", &maximums[i]);
    }

    qsort(prices, n, sizeof(ll), compare);
    qsort(maximums, m, sizeof(ll), compare);

    int last_index = n - 1;

    for (int i = 0; i < m; i++) {
        printf("%lld\n", find_ticket(prices, &last_index, maximums[i]));
    }

    free(prices);
    free(maximums);

    return 0;
}
