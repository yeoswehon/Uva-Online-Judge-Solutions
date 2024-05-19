#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string addInteger(string a, string b){
    if (a.length() > b.length()) (swap(a,b)); // second number bigger
    int carry = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string result = "";
    for (int i = 0; i < b.length();i++){
        int d1 = i < a.length() ? a[i] - '0' : 0;
        int d2 = b[i] - '0';
        int sum = d1 + d2 + carry;
        int output_digit = sum % 10;
        carry = sum /10;
        result.push_back(output_digit + '0');
    }
    if (carry) result.push_back('1');
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n--){
        string a,b;
        cin >> a >> b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string temp = addInteger(a,b);
        while (temp.back() == '0') { 
            temp.pop_back();
        }
        reverse(temp.begin(),temp.end());
        cout << temp << endl;
    }
}
