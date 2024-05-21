#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedenceCheck(char c) {
    return (c == '*' || c == '/') ? 1 : 0;
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int j = 1; j <= n; j++) {
        stack<char> st;
        st.push('(');
        string expr = "";
        string token;
        while (true) {
            getline(cin, token);
            if (token.empty() || !cin) break;
            else expr += token[0];
        }
        expr += ')';
        int length = expr.length();
        if (j > 1) printf("\n");
        for (int i = 0; i < length; i++) {
            if (expr[i] >= '0' && expr[i] <= '9') printf("%c", expr[i]); // Case of a number
            else if (expr[i] == '(') st.push('(');
            else if (expr[i] == ')') {
                while (st.top() != '(') {
                    printf("%c", st.top());
                    st.pop();
                }
                st.pop(); // removes '('
            }
            else { // If it is an operator, compare precedence
                while (!st.empty() && st.top() != '(' && precedenceCheck(expr[i]) <= precedenceCheck(st.top())) {
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(expr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
