
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int i) {
    if (i <= 1) return false;
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) return false;
    }
    return true;
}

int power(int b, int e) {
    int result = 1;
    for (int i = 0; i < e; i++) {
        result *= b;
    }
    return result;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (is_prime(n)) {
        printf("%d is prime\n", n);
        return 0;
    }

    for (int b = 2; b < n; b++) {
        for (int e = 2; ; e++) {
            int result = power(b, e);
            if (result == n) {
                printf("%d = %d^%d\n", n, b, e);
                return 0;
            } else if (result > n) {
                break;
            }
        }
    }

    printf("Too difficult\n");
    return 0;
}
