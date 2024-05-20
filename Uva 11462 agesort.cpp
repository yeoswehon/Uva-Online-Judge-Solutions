#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> age_frequency(101, 0); 
        int age;
        while (n--) {
            cin >> age;
            ++age_frequency[age]; 
        }
        bool first_age = true;
        for (int i = 1; i <= 100; i++) {
            while (age_frequency[i]--) {
                if (!first_age) {
                    cout << " ";
                } else {
                    first_age = false;
                }
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
