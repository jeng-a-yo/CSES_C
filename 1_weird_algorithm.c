#include <stdio.h>

int main(void) {
    
    long long int num;
    scanf("%lld", &num);

    while (num != 1) {
        printf("%lld ", num);
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
    }
    printf("%lld\n", num);

    return 0;
}