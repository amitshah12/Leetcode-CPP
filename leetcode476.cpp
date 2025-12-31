#include <iostream>
#include <cmath>
using namespace std;

/* Leetcode-1009. Complement of Base 10 Integer
   Leetcode-476. Number Complement

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231
*/

class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int result = 0;
        
        if(num == 0){
            return 1;
        }
        while(num){
            int r = num % 2;
            result += (pow(2,count)* !r);
            count ++;
            num = num / 2;
        }
        return result;
    }
};

int main() {
    int num = 1;

    Solution sol;
    int ans = sol.findComplement(num);

    cout << "Output: " << ans << endl;

    return 0;
}