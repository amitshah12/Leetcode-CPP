#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Tolerance value to handle floating point precision errors.
    // Example: 23.9999 should be considered equal to 24.
    double epsilon = 0.1; 

    // Recursive helper function: Try all combinations of numbers & operations.
    bool solve(vector<double>& cards) {
        // Base case: If only one number left, check if it equals 24.
        if(cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        // Try picking every possible pair (i, j).
        for(int i = 0; i < cards.size(); i++) {
            for(int j = 0; j < cards.size(); j++) {
                if(i == j) 
                    continue; // Skip same index

                // Prepare a new vector by removing i and j
                vector<double> temp;
                for(int k = 0; k < cards.size(); k++) {
                    if(k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                // Current chosen pair of numbers
                double a = cards[i];
                double b = cards[j];

                // All possible results from applying operations on (a, b)
                vector<double> possibleVal = {a + b, a - b, a * b};

                // Division: Add only if denominator is non-zero
                if(abs(b) > 0.0) {
                    possibleVal.push_back(a / b);
                }

                // Explore each operation result recursively
                for(double val : possibleVal) {
                    temp.push_back(val);   // Do: add result into list
                    if(solve(temp)) {     // Explore further
                        return true;      // If any branch works, return true
                    }
                    temp.pop_back();      // Undo: backtrack
                }
            }
        }

        return false; // No way to make 24
    }

    // Wrapper function: Convert int cards to double, then start recursion
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i = 0; i < cards.size(); i++) {
            nums.push_back(1.0 * cards[i]); // Convert to double
        }
        return solve(nums);
    }
};

// ---------------- Main Function ----------------
int main() {
    Solution sol;

    // Example test cases
    vector<int> cards1 = {4, 1, 8, 7}; 
    // Expected: true (8 * (7 - 4) = 24)

    vector<int> cards2 = {1, 2, 1, 2}; 
    // Expected: false (no way to make 24)

    cout << "Test 1 -> {4,1,8,7}: " 
         << (sol.judgePoint24(cards1) ? "Possible" : "Not Possible") << endl;

    cout << "Test 2 -> {1,2,1,2}: " 
         << (sol.judgePoint24(cards2) ? "Possible" : "Not Possible") << endl;

    return 0;
}
