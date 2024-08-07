#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool can_empty_piles(long int a, long int b) {
    if ((a + b) % 3 != 0) return false;
    if (a > 2 * b || b > 2 * a) return false;
    return true;
}

int main(void) {

    int n;
    scanf("%d", &n);

    long int *array_a = (long int*) malloc(n * sizeof(long int));
    long int *array_b = (long int*) malloc(n * sizeof(long int));    

    for (int i = 0; i < n; i++) {
        scanf("%ld %ld", &array_a[i], &array_b[i]);
    }

    for (int i = 0; i < n; i++) {
        can_empty_piles(array_a[i], array_b[i]) ? printf("YES\n") : printf("NO\n");
    }

    free(array_a);
    free(array_b);

    return 0;
}