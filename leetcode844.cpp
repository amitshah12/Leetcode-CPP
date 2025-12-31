#include <iostream>
#include <stack>
using namespace std;

/*leetcode-844. Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/

//Method-1
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char>s1;
        for(char ch : s){
            if(ch != '#'){
                s1.push(ch);
            } else if(!s1.empty()) {
                s1.pop();
            }
        }

        stack<char>s2;
        for(char ch : t){
            if(ch != '#'){
                s2.push(ch);
            } else if(!s2.empty()){
                s2.pop();
            }
        }

        if(s1 == s2){
            return true;
        }
        return false;
    }
};

//Method-2

int main() {
    string s = "ab#c";
    string t = "ad#c";

    Solution sol;
    bool ans = sol.backspaceCompare(s,t);

    cout << "Output: "<< ans << endl;

    return 0;
}