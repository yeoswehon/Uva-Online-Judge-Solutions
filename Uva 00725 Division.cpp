#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    bool isFirst = true;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (!isFirst) {
            cout << endl;
        } else {
            isFirst = false;
        }
        bool hasSolution = false;
        for (int fghij = 1234; fghij <= 98765 / n; fghij++) {
            int abcde = fghij * n;
            int temp, used = (fghij < 10000);
            temp = abcde;
            while (temp) {
                used |= (1 << temp % 10);
                temp /= 10;
            }
            temp = fghij;
            while (temp) {
                used |= (1 << temp % 10);
                temp /= 10;
            }
            if (used == (1<<10) -1) {
                hasSolution = true;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if (!hasSolution) {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
