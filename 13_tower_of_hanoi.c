#include <stdio.h>
#include <math.h>

// Function to perform the Tower of Hanoi moves
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("%d %d\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("%d %d\n", from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int total_moves = (1 << n) - 1;
    printf("%d\n", total_moves);

    int count = 0;
    tower_of_hanoi(n, 1, 3, 2);

    return 0;
}
