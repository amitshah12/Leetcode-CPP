#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        
        string result;  // Acts like a stack to build the final answer
        
        // lastIdx[c] stores the last index of character 'c' in the string
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < n; i++) {
            lastIdx[s[i]-'a'] = i;
        }

        // taken[c] tells whether character 'c' is already in result
        vector<bool> taken(26, false);

        // Traverse the string character by character
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            // If character is already included, skip it
            if(taken[idx]){
                continue;
            }

            /*
             Remove characters from the end of result if:
             1. result is not empty
             2. current character is smaller (lexicographically)
             3. the character at result.back() appears again later
            */
            while(!result.empty() &&
                  result.back() > ch &&
                  lastIdx[result.back()-'a'] > i){
                
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Add current character to result
            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};


int main() {
    string s = "bcabc";

    Solution sol;
    string ans = sol.removeDuplicateLetters(s);

    cout << "Output:" << ans << endl;

    return 0;
}