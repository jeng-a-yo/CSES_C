#include <stdio.h>

#define MOD 1000000007

// Function to compute (base^exp) % mod
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    scanf("%lld", &n);
    
    // Calculate 2^n % MOD
    long long result = power_mod(2, n, MOD);
    
    // Print the result
    printf("%lld\n", result);
    
    return 0;
}
