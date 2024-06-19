#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define read(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define rep(i,a,b) for (int i = a; i < b; i++)
using namespace std;

int main() {
    int c, s, cases = 1;
    while (cin >> c >> s && c != 0 && s != 0) {
        vi mass(2*c,0);
        double total = 0, imbalance = 0;
        read(mass, s);
        total = accumulate(mass.begin(),mass.end(),0);
        sort(mass.begin(),mass.end());
        total /= (c); // Calculate average
        printf("Set #%d\n", cases++);
        for (int i = 0; i < c; i++) {
            printf(" %d:", i);
            if (mass[i]) printf(" %d", mass[i]);
            if (mass[2 * c - i - 1]) printf(" %d", mass[2 * c - i - 1]);
            printf("\n");
            imbalance += abs(total - (mass[i] + mass[2 * c - i - 1]));
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}
