#include <cstdio>

int main() {
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9/5) + 32;
    printf("Fahrenheit: %.2f\n", fahrenheit);
    return 0;
}
