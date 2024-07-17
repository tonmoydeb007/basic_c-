#include <cstdio>

int main() {
    int num, original, reversed = 0;
    scanf("%d", &num);
    original = num;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    if (original == reversed)
        printf("%d is a palindrome\n", original);
    else
        printf("%d is not a palindrome\n", original);
    return 0;
}
