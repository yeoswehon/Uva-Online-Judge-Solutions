#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    while (cin >> N) {   
        vector<int> weights; // Store values of weights
        for (int i = 0; i < (1 << N); i++) {
            int weight;
            cin >> weight; // Receive 2^N amount of input for an n-dimensional cube
            weights.push_back(weight);
        }

        vector<int> potency_values((1 << N), 0); // Initialize potency_values with size and all elements as 0
        for (int i = 0; i < (1 << N); i++) { 
            // Calculate potency for each corner
            for (int j = 0; j < N; j++) {
                potency_values[i] += weights[i ^ (1 << j)];
            }
        }

        int max_potency_sum = INT_MIN;
        // Find maximum potency sum for 2 neighboring corners (still use XOR)
        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                max_potency_sum = max(max_potency_sum, potency_values[i] + potency_values[i ^ (1 << j)]);
            }
        }
        cout << max_potency_sum << endl;
    }
    return 0;
}
