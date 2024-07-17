#include <cstdio>

int main() {
    int num, sum = 0;
    scanf("%d", &num);
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    printf("Sum of digits: %d\n", sum);
    return 0;
}
