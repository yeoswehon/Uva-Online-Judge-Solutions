#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve() {
    int n;
    bool first = true;
    while (scanf("%d", &n), n) {
        if (!first) {
            cout << endl;
        } else {
            first = false;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int a = 0; a < n - 5; a++)
            for (int b = a + 1; b < n - 4; b++)
                for (int c = b + 1; c < n - 3; c++)
                    for (int d = c + 1; d < n - 2; d++)
                        for (int e = d + 1; e < n - 1; e++)
                            for (int f = e + 1; f < n; f++)
                                cout << v[a] << " " << v[b] << " " << v[c] << " "
                                     << v[d] << " " << v[e] << " " << v[f] << endl;
    }
}

int main() {
    solve();
    return 0;
}
