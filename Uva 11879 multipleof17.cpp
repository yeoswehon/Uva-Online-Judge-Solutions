#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    string n;
    while (cin >> n && (n!="0")) {
        int remainder = 0;
        for (char c: n) {
            remainder = remainder*10 + (c-'0');
            remainder %=17;
        }
        if (remainder%17==0) (cout << 1 << endl);
        else (cout << 0 << endl);
    }
    return 0;
}
