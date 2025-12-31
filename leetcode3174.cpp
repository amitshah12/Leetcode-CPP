#include <iostream>
//#include <string>
using namespace std;

/* Leetcode 3174 : Clear Digits
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
Example 1:
Input: s = "abc"
Output: "abc"
Explanation:
There is no digit in the string.

Example 2:
Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes "".
*/

class Solution {
    public:
        string clearDigits(string s) {
            string result;
            for(int i=0; i<s.length(); i++){  // Iterate using index 
                if(s[i]>='0' & s[i]<='9'){  // Check if character is a digit
                    result.pop_back();
                } else {
                    result.push_back(s[i]);      // Append non-digit characters
                }
            }
            return result;
        }
    };
int main() {
    Solution sol;

    cout << sol.clearDigits("ab2c3d") << endl;  // Expected output: "ad"
    cout << sol.clearDigits("12345") << endl;  // Expected output: "" (empty string)
    cout << sol.clearDigits("abc") << endl;
    
    return 0;
}