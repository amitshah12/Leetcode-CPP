#include <iostream>
using namespace std;

/*leetcode-9. Palindrome number
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

class Solution {
    int reverseDigit(int x){
        long rev = 0;
        int remainder = 0;

        while(x>0){
            remainder = x % 10;
            rev = rev * 10 + remainder;
            x = x / 10;
        }
        return rev;
    }
public:
    bool isPalindrome(int x) {
        long reverse = reverseDigit(x);
        return (reverse == x);
    }
};

int main() {
    int x = 121;

    Solution sol;
    bool ans = sol.isPalindrome(x);

    cout << "Output = " << ans << endl;
    return 0;
}