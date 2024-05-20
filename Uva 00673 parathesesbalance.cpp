#include <iostream>
#include <stack>
using namespace std;

bool isOpening(char a) {
    return (a == '(' || a == '[');
}

bool isClosed(char b) {
    return (b == ')' || b == ']');
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Stop reading the \n from cin >> n
    while (n--) {
        string s;
        stack<char> brackets;
        getline(cin,s); // To read the entire line including spaces (cin stops my input at spaces)
        int len = s.length();
        int i = 0;
        for (i = 0; i < len; i++) {
            if (isOpening(s[i])) {
                brackets.push(s[i]);
            }
            else if (isClosed(s[i])) {
                if (brackets.empty()) { // Can't have closing without any opening bracket
                    break;
                }
                else if (s[i] == ')' && brackets.top() != '(') {
                    break; 
                }
                else if (s[i] == ']' && brackets.top() != '[') {
                    break; 
                }
                brackets.pop(); 
            }
        }
        if (!brackets.empty() || i < len) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
