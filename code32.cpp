#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    int result = factorial(n) / (factorial(r) * factorial(n - r));
    cout << "nCr = " << result << endl;

    return 0;
}
