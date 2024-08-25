#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;  // Error handling
    }

    int *arr = (int*)malloc((n + 1) * sizeof(int));
    int *pos = (int*)malloc((n + 1) * sizeof(int));

    if (!arr || !pos) {
        free(arr);
        free(pos);
        return 1;  // Memory allocation failed
    }

    // Read the input and store the positions of each number
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(pos);
            return 1;  // Error handling
        }
        pos[arr[i]] = i;
    }

    // Initialize round count
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d", &a, &b) != 2) {
            free(arr);
            free(pos);
            return 1;  // Error handling
        }

        int x = arr[a], y = arr[b];

        // Check if x and x-1 were initially in order and won't be after the swap
        if (x > 1 && pos[x-1] < a && b < pos[x-1]) rounds++;
        if (x > 1 && pos[x-1] > a && b > pos[x-1]) rounds--;

        // Check if x and x+1 were initially in order and won't be after the swap
        if (x < n && pos[x+1] > a && b > pos[x+1]) rounds++;
        if (x < n && pos[x+1] < a && b < pos[x+1]) rounds--;

        // Check if y and y-1 were initially in order and won't be after the swap
        if (y > 1 && pos[y-1] < b && a < pos[y-1]) rounds++;
        if (y > 1 && pos[y-1] > b && a > pos[y-1]) rounds--;

        // Check if y and y+1 were initially in order and won't be after the swap
        if (y < n && pos[y+1] > b && a > pos[y+1]) rounds++;
        if (y < n && pos[y+1] < b && a < pos[y+1]) rounds--;

        // Special case: if x and y are adjacent numbers
        if (abs(x - y) == 1) {
            int min = x < y ? x : y;
            if (pos[min] > pos[min+1]) rounds--;
            else rounds++;
        }

        // Perform the swap
        swap(&arr[a], &arr[b]);
        pos[x] = b;
        pos[y] = a;

        printf("%d\n", rounds);
    }

    free(arr);
    free(pos);

    return 0;
}