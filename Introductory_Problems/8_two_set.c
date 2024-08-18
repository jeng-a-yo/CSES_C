#include <stdio.h>
#include <stdlib.h>

void two_set(long int n) {
    long long int total_sum = n * (n + 1) / 2;
    if (total_sum % 2 == 1) {
        printf("NO\n");
        return;
    }

    long int *array_1 = (long int*) malloc(n * sizeof(long int));
    long int *array_2 = (long int*) malloc(n * sizeof(long int));

    long int target = total_sum / 2;
    long int len_1 = 0, len_2 = 0;

    for (long int num = n; num > 0; num--) {
        if (target >= num) {
            array_1[len_1++] = num;
            target -= num;
        } else {
            array_2[len_2++] = num;
        }
    }

    printf("YES\n");
    printf("%ld\n", len_1);
    for (int i = 0; i < len_1; i++) {
        printf("%ld ", array_1[i]);
    }
    printf("\n%ld\n", len_2);
    for (int i = 0; i < len_2; i++) {
        printf("%ld ", array_2[i]);
    }
    printf("\n");

    free(array_1);
    free(array_2);
}

int main(void) {
    long int n;
    scanf("%ld", &n);

    two_set(n);

    return 0;
}
