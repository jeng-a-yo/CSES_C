#include <stdio.h>
#include <stdlib.h>

long int get_spiral_number(long int r, long int c) {
    long int r_num;
    if (r >= c) {
        if (r % 2 == 0) {
            r_num = r * r - c + 1;
        } else {
            r_num = (r - 1) * (r - 1) + c;
        }
    } else {
        if (c % 2 == 0) {
            r_num = (c - 1) * (c - 1) + r;
        } else {
            r_num = c * c - r + 1;
        }
    }
    return r_num;
}

int main(void) {
    int n;
    scanf("%d", &n);

    // Allocate memory for the arrays
    long int *r_list = (long int *)malloc(n * sizeof(long int));
    long int *c_list = (long int *)malloc(n * sizeof(long int));

    // Check if memory allocation was successful
    if (r_list == NULL || c_list == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%ld %ld", &r_list[i], &c_list[i]);
    }

    // Print the spiral number for each pair
    for (int i = 0; i < n; i++) {
        printf("%ld\n", get_spiral_number(r_list[i], c_list[i]));
    }

    // Free the allocated memory
    free(r_list);
    free(c_list);

    return 0;
}
