#include <iostream>
using namespace std;

/*520. Detect Capital
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

Constraints:
1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
*/

//Method-1
/*
class Solution {
public:
    bool allCapital(string word){

        for(char ch : word){
            if(ch < 'A' || ch > 'Z'){
                return false;
            }
        }
        return true;
    }
    
    bool allSmall(string word){
        for(char ch : word){
            if(ch < 'a' || ch > 'z'){
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string word) {

        if(allCapital(word) || allSmall(word) || allSmall(word.substr(1))){
            return true;
        }
        return false;
    }
};
*/

//Method-2
class Solution {
public:
    
    bool detectCapitalUse(string word) {
        int countCapitals = 0;

        for(char ch : word){
            if(isupper(ch)){
                countCapitals++;
            }

        }
        if(countCapitals == 0 || countCapitals == word.length() || (countCapitals == 1 && isupper(word[0]))){
            return true;
        }
        return false;
    }
};



int main() {
    string word = "USA";
    // string word = "FlaG";

    Solution sol;
    bool ans = sol.detectCapitalUse(word);

    cout << "Output : " << ans << endl;

    return 0;
}