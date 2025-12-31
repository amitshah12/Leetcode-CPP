#include <iostream>
using namespace std;

/* Leetcode 58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        
        int i = n-1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        int length = 0;
        while(i >= 0  && s[i] != ' '){
            i--;
            length++;
        }
        return length;
    }
};

int main() {
    string s = "Hello World";

    Solution sol;
    int ans = sol.lengthOfLastWord(s);

    cout << "The length of last word in the string is " << ans << endl;
    
    return 0;
}