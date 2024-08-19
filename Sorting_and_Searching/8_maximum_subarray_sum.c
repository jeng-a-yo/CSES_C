#include <stdio.h>

typedef long long int ll;

int main() {
    int n;
    scanf("%d", &n);
    
    ll a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    ll max_sum = a[0];
    ll current_sum = a[0];

    for (int i = 1; i < n; i++) {
        if (current_sum + a[i] > a[i]) {
            current_sum = current_sum + a[i];
        } else {
            current_sum = a[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("%lld\n", max_sum);
    
    return 0;
}
