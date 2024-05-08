#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n; 
    while (n--) {
        long long m;
        cin >> m;
        int result = (-1 + sqrt(1 + 8 * m)) / 2;
        cout << result << endl; 
}
    return 0;
}
