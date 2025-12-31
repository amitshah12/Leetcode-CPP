#include <iostream>
#include <algorithm>
using namespace std;

/*Leetcode-557. Reverse Words in a String III
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
*/

//Method -1
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        for(int i = 0; i<n; i++){
            if(s[i] != ' '){
                int j = i;

                while(j < n && s[j] != ' '){
                    j++;
                }
                reverse(s.begin()+i, s.begin()+j);
                i = j;
            }
        }
        return s;
    }
};

int main() {
    string s = "Let's take LeetCode contest";

    Solution sol;
    string ans = sol.reverseWords(s);

    cout << "Output: " << ans << endl;

    return 0;
}