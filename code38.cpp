#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    printf("Factorial: %lld\n", factorial);
    return 0;
}
