#include <iostream>
using namespace std;

/*Leetcode-3084. Count Substrings Starting and Ending with Given Character

You are given a string s and a character c. Return the total number of substrings of s that start and end with c.

Example 1:
Input: s = "abada", c = "a"
Output: 6
Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Example 2:
Input: s = "zzz", c = "z"
Output: 6
Explanation: There are a total of 6 substrings in s and all start and end with "z".

Constraints:
1 <= s.length <= 105
s and c consist only of lowercase English letters.
*/

/*
//Method-1
class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        long long cCnt = 0;
        long long count = 0;

        for(char x : s){
            if(x == c){
                count = count + (1 + cCnt);
                cCnt++;
            }
        }
        return count;
    }
};
*/


//Method-2
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        
        for(char &ch : s) {
            if(ch == c) {
                count++;
            }
        }
        
        
        return count *(count-1)/2 + count;
    }
};


int main() {
    string s = "abada";
    char c = 'a';

    Solution sol;
    int ans = sol.countSubstrings(s,c);

    cout << "Output: " << ans << endl;

    return 0;
}