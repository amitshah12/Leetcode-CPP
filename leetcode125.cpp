#include <iostream>
using namespace std;

/*Leetcode 125 - Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

class Solution{
    bool valid(char ch){
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return 1;
        } else {
            return 0;
        }
    }

    char toLowerCase(char ch){
        if((ch >='a' && ch <= 'z') || ch >='0' && ch <= '9'){
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp; 
        }
    }

    bool checkPalindrome(string a){
        int s = 0;
        int e = a.length()-1;

        while(s<=e){
            if(a[s] != a[e]){
                return 0;
            } else {
                s++;
                e--;
            }
        }
        return 1;
    }

    public:
    bool isPalindrome(string s){
        string temp = "";

        for(int j=0; j<s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        //Convert to Lowercase
        for(int j = 0; j<temp.length(); j++){
            temp[j] = toLowerCase(temp[j]);
        }

        return checkPalindrome(temp);
    }
};

int main() {

    //string s = "A man, a plan, a canal: Panama";
    string s = "Mam";

    Solution sol;
    bool ans = sol.isPalindrome(s);

    cout << ans << endl;

    
    
    return 0;
}