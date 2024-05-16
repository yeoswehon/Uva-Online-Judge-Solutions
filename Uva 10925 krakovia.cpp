#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int chartodigit(char a) {
    return a - '0';
}

char digittochar(int a) {
    return a + '0';
}

string addition_two_integers(string a, string b) {
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

string division_of_numbers(string a, int divisor) {
    string result;
    int idx = 0;
    int temp = chartodigit(a[idx]);

    // Add digits until temp >= divisor hence temp < divisor case is considered
    while (temp < divisor && (idx < a.length()-1)) {
        temp = temp * 10 + chartodigit(a[++idx]);
    }

    while (idx < a.length()) {
        result += digittochar((temp / divisor));
        temp = (temp % divisor) * 10 + chartodigit(a[++idx]);
    }

    if (result.empty()) return "0";
    return result;
}

int main() {
    int N, people;
    int case_num = 0;
    while (cin >> N >> people && (N != 0)) {
        case_num++;
        string amount_intake;
        string total_cost = "0";
        while (N--) {
            cin >> amount_intake;
            total_cost = addition_two_integers(total_cost, amount_intake);
        }
        string each_pay = division_of_numbers(total_cost, people);
        cout << "Bill #" << case_num << " costs " << total_cost << ": each friend should pay " << each_pay << "\n\n";
    }
    return 0;
}
