#include <iostream>
#include <vector>
using namespace std;

/*Leetcode-28. Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

class Solution {
public:
    int strStr(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(s1[i+j] != s2[j]){
                    break;
                }

                if(j == n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    string s1 = "sadbutsad";
    string s2 = "sad";

    Solution sol;
    int ans = sol.strStr(s1, s2);

    cout << "Output: " << ans << endl;
    return 0;
}