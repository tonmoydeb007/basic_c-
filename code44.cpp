#include <cstdio>
#include <cmath>

int main() {
    int base, exp;
    scanf("%d %d", &base, &exp);
    printf("Result: %lld\n", (long long)pow(base, exp));
    return 0;
}
