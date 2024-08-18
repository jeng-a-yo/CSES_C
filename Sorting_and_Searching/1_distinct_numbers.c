#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

// Comparison function to be used with qsort
int compare(const void *a, const void *b) {
    ll arg1 = *(const ll *)a;
    ll arg2 = *(const ll *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    ll *arr = (ll *)malloc(n * sizeof(ll));
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    // Sort the array
    qsort(arr, n, sizeof(ll), compare);
    
    // Count distinct elements
    int distinct_count = 1; // There is at least one element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            distinct_count++;
        }
    }
    
    printf("%d\n", distinct_count);
    
    free(arr);
    
    return 0;
}
