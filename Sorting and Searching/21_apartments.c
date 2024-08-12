#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(ll*)a - *(ll*)b);
}

// CSES Apartments
int main(void) {

    long int n, m, k;
    scanf("%ld %ld %ld", &n, &m, &k);

    ll* apartments_array = (ll*) malloc(n * sizeof(ll));
    ll* applicants_array = (ll*) malloc(m * sizeof(ll));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &apartments_array[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%lld", &applicants_array[i]);
    }

    // Sort both arrays
    qsort(apartments_array, n, sizeof(ll), compare);
    qsort(applicants_array, m, sizeof(ll), compare);

    int i = 0, j = 0;
    int count = 0;

    // Greedy approach to match apartments with applicants
    while (i < n && j < m) {
        if (llabs(apartments_array[i] - applicants_array[j]) <= k) {
            // We have a match
            count++;
            i++;
            j++;
        } else if (apartments_array[i] < applicants_array[j]) {
            // Move to the next apartment
            i++;
        } else {
            // Move to the next applicant
            j++;
        }
    }

    // Output the number of matches
    printf("%d\n", count);

    // Free allocated memory
    free(apartments_array);
    free(applicants_array);

    return 0;
}
