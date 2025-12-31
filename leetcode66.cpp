#include <iostream>
#include <vector>
using namespace std;

/*Leetcode-66.Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
digits: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [9]
digits: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 
Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }

            // If digit is 9, it becomes 0 and we carry over
            digits[i] = 0;
        }

        // If we exit the loop, it means all digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};


int main() {
    //vector<int> digits = {9};
    vector<int> digits = {4,3,2,1};
    //vector<int> digits = {1,2,3};

    Solution sol;
    vector<int> Outputs = sol.plusOne(digits);

    cout << "output = [";
    for (int i = 0; i < digits.size(); ++i)
    {
        cout << digits[i];
        if(i<digits.size()-1){
            cout << ",";
        }
    }
    cout << "]\n";

    return 0;
}