#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int chartodigit(char a) {
    return a - '0';
}

char digittochar(int a) {
    return a + '0';
}

string addinteger(string a, string b) {
    if (a.length() > b.length()) {
        swap(a, b); 
    }
    string result = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;

    for (int i = 0; i < a.length(); i++) {
        int d1 = chartodigit(a[i]);
        int d2 = chartodigit(b[i]);
        int sum = d1 + d2 + carry;
        int output_digit = sum % 10; 
        carry = sum / 10;
        result.push_back(digittochar(output_digit));
    }

    for (int i = a.length(); i < b.length(); i++) {
        int d1 = chartodigit(b[i]);
        int sum = carry + d1;
        int output_digit = sum % 10;
        carry = sum / 10;
        result.push_back(digittochar(output_digit));
    }

    if (carry) result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

string multiplyinteger(string a, string b) {
    int n = a.size();
    int m = b.size();
    string result(n + m, '0'); // Initialize result to hold the maximum possible length
    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            int product = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = product % 10 + '0';
            carry = product / 10;
        }
        result[i] += carry; // Add carry to the current digit
    }

    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

string pow_integer(int base, int exp) {
    string result = "1";
    for (int i = 0; i < exp; ++i) {
        result = multiplyinteger(result, to_string(base));
    }
    return result;
}

int main() {
    int n, a;
    while (cin >> n >> a) {
        string sum = "0";
        for (int i = 1; i <= n; i++){
            string i_str = to_string(i);
            string temp = multiplyinteger(i_str, pow_integer(a, i));
            sum = addinteger(sum, temp);
        }
        cout << sum << endl;
    }
    return 0;
}
