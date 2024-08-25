#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], pos[n + 1];

    // Read the input and store the positions of each number
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        pos[arr[i]] = i;
    }

    int rounds = 1;

    // Count the number of rounds needed
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }

    printf("%d\n", rounds);

    return 0;
}
