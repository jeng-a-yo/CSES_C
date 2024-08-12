#include <stdio.h>

int main(void) {

    long long int n;
    scanf("%lld", &n);

    long long int muitiple_of_5 = 5;
    int sum = 0;

    while (n >= muitiple_of_5) {
        sum += n / muitiple_of_5;
        muitiple_of_5 *= 5;
    }
    printf("%d\n", sum);

    return 0;
}