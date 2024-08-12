#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    char str[1000001]; // Array size is 1 more than 100000 to accommodate null terminator
    fgets(str, sizeof(str), stdin);

    long long int current_len = 1, max_len = 1; // Initialize to 1 since minimum repetition length is 1

    // Loop through the string until the null terminator or newline
    for (long long int i = 1; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == str[i - 1]) {
            current_len++;
        } else {
            max_len = MAX(max_len, current_len);
            current_len = 1;
        }
    }
    // Check the last segment after the loop
    max_len = MAX(max_len, current_len);

    printf("%lld\n", max_len);

    return 0;
}