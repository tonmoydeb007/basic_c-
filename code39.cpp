#include <cstdio>

int main() {
    int num;
    scanf("%d", &num);
    bool isPrime = true;
    if (num <= 1) isPrime = false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        printf("%d is prime\n", num);
    else
        printf("%d is not prime\n", num);
    return 0;
}
