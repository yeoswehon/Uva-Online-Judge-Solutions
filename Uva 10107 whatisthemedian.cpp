#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num;
    
    while (cin >> num) {
        numbers.push_back(num);
        sort(numbers.begin(), numbers.end());
        
        int size = numbers.size();
        int median;
        
        if (size % 2 == 0) {
            median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2; // Because indexing starts from 0.
        } else {
            median = numbers[size / 2];
        }
        
        cout << median << endl;
    }
    
    return 0;
}
