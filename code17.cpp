#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum (int): " << add(3, 7) << endl;
    cout << "Sum (double): " << add(3.5, 7.2) << endl;
    return 0;
}
