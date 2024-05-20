#include <iostream>
#include <stack>
using namespace std;

bool isOpening(char a) {
    return (a == '(' || a == '[' || a == '{' || a == '<');
}

bool isClosed(char b) {
    return (b == ')' || b == ']' || b == '}' || b == '>');
}

int main() {
    string input;
    while (cin >> input) {
        stack<char> brackets;
        int position = 0;
        int length = input.length();
        int i =0;
        for (i = 0; i < length; i++) {
            position++;
            if (isOpening(input[i])) {
                if (input[i] == '(' && input[i+1] == '*') {
                    brackets.push('*');
                    i++;
                } else {
                    brackets.push(input[i]);
                }
            } else if (isClosed(input[i]) || (input[i] == '*' && input[i+1] == ')')) {
                if (brackets.empty()) break;
                if (input[i] == '*') {
                    if (brackets.top() != '*') break;
                    brackets.pop();
                    i++;
                } else if (input[i] == ')') {
                    if (brackets.top() != '(') break;
                    brackets.pop();
                } else if (input[i] == ']') {
                    if (brackets.top() != '[') break;
                    brackets.pop();
                } else if (input[i] == '}') {
                    if (brackets.top() != '{') break;
                    brackets.pop();
                } else if (input[i] == '>') {
                    if (brackets.top() != '{') break;
                    brackets.pop();
                }
            }
        }
        if (!brackets.empty() || i < length) { // Unmatched opening means i == length, unmatched closed i < length
            if (i == length && !brackets.empty()) position++;
            cout << "NO " << position << endl;
        } 
        else { 
            cout << "YES" << endl;
        }
    }
    return 0;
}
