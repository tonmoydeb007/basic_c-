#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int n = s.size(), start = 0, maxLen = 1;

    bool table[n][n] = {false};

    for (int i = 0; i < n; ++i) {
        table[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (table[i][j - 1] && s[i] == s[j]) {
                table[i][j] = true;
                start = i;
                maxLen = k;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is " << result << endl;

    return 0;
}
