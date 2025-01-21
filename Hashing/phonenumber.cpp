#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a = "1010", b = "1011";
    int carry = 0;
    string ans = "";

    // Make both strings the same length by padding with zeros
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;

    // Traverse from the last character to the first
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == '1' && b[i] == '1') {
            if (carry == 1) {
                ans += '1';
            } else {
                ans += '0';
            }
            carry = 1;
        } else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
            if (carry == 1) {
                ans += '0';
                carry = 1;
            } else {
                ans += '1';
                carry = 0;
            }
        } else if (a[i] == '0' && b[i] == '0') {
            if (carry == 1) {
                ans += '1';
                carry = 0;
            } else {
                ans += '0';
            }
        }
    }

    // If there's a carry left, add it to the result
    if (carry == 1) {
        ans += '1';
    }

    // Reverse the result to get the final binary sum
    reverse(ans.begin(), ans.end());

    cout << "Result: " << ans << endl;
    return 0;
}
