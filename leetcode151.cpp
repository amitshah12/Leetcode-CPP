#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

/*Leetcode -151. Reverse Words in a String
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

//Method-1
// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.length();

//         reverse(s.begin(), s.end());

//         string ans = "";
//         for(int i = 0; i<n; i++){
//             string word = "";
//             while(i<n && s[i] != ' '){
//                 word += s[i];
//                 i++;
//             }

//             reverse(word.begin(), word.end());
//             if(word.length()>0){
//                 ans += " " + word;
//             }
//         }
//         return ans.substr(1);
//     }
// };

//Method-2
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        
        string result = "";

        // Step 1: Extract words
        while(ss >> token){   // automatically skips multiple spaces
            result = token + " " + result;
        }

        return result.substr(0,result.length()-1);
    }
};
int main() {
    string s = "the sky is blue";

    Solution sol;
    string Output = sol.reverseWords(s);

    cout << "Reversed string : " << Output << endl;

    return 0;
}