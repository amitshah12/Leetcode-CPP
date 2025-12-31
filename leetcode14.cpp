#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Leetcode-14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        string answer = strs[0];
        for(int i=1; i<strs.size(); i++){
            int j =0;
            while(j < answer.size() && j<strs[i].size() && answer[j] == strs[i][j]){
                j++;
            }
            answer = answer.substr(0, j);
            if(answer == ""){
                break;
            }
        }
        return answer;
    }
};

int main() {
    int n;
    cout << "Enter number of string: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter string (commonstr + identicalstr):\n";
    for (int i = 0; i < strs.size(); i++) {
        cin >> strs[i];
    }

    Solution sol;
    string Answer = sol.longestCommonPrefix(strs);
    cout << "Longest common prefix is: " << Answer << endl;
    return 0;
}