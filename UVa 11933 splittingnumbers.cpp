// UVa 11933
#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int N;
    while (cin >> N && N != 0) {
        int a = 0, b = 0;
        long long multiplier = 1;
        bool flag = true; // true means a, false means b

        while (N > 0) {
            int bitmask = N & 1;
            if (bitmask==1) {
            if (flag) (a += multiplier);
            else (b+= multiplier);
            flag = !flag;
            }
            multiplier *=2;
            N >>=1;    
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
