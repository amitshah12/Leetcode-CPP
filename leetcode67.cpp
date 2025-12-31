#include <iostream>
#include <algorithm>
using namespace std;

/*Leetcode-67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1;
        int n = b.length()-1;

        string result = "";

        int carry = 0;
        int sum = 0;

        while(m>=0 || n>=0){
            sum = carry;

            if(m>=0){
                sum += (a[m]-'0');
                m--;
            }
            if(n>=0){
                sum += (b[n]-'0');
                n--;
            }
            result.push_back((sum%2==0) ? '0' : '1');
            carry = (sum>1) ? 1 : 0;
        }
        if(carry){
            result.push_back('1');
        }
        reverse(begin(result),end(result));
        return result;
    }
};

int main() {
    string a = "11";
    string b = "1";

    Solution sol;
    string ans = sol.addBinary(a,b);

    cout << "Output : " << ans << endl;

    return 0;
}