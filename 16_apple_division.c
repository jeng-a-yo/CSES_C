#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))


int n;
long long int apples[20];
long long int min_diff = 1e18;

void get_min_diff(int i, long long int sum1, long long int sum2) {

    if (i == n) {
        min_diff = min(min_diff, llabs(sum1 - sum2));
        return;
    }
    get_min_diff(i + 1, sum1 + apples[i], sum2);
    get_min_diff(i + 1, sum1, sum2 + apples[i]);

}

int main(void) {


    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &apples[i]);
    }

    get_min_diff(0, 0, 0);

    printf("%lld\n", min_diff);

    return 0;
}