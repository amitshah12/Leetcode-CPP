#include <iostream>
#include <unordered_set>
using namespace std;

/* 1704. Determine if String Halves Are Alike
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 
Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/

//method-1
/*
class Solution {
public:
    bool isVowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();

        int i = 0;
        int j = n/2;

        int leftCount = 0;
        int rightCount = 0;

        //set<string> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        while(i<n/2 && j<n){
            if(isVowel(s[i])){
                leftCount++;
            }

            if(isVowel(s[j])){
                rightCount++;
            }
            i++;
            j++;
        }

        if(leftCount == rightCount){
            return true;
        }
        return false;
    }
};
*/

//Method -2
class Solution {
public:
    bool halvesAreAlike(string s) {
       int n = s.length();
       
       int i = 0;
       int j = n/2;

       int leftCount = 0;
       int rightCount = 0;

       /* idea -1
       unordered_set<char> st;
       st = {'a', 'e', 'i', 'o', 'u',
             'A', 'E', 'I', 'O', 'U'
            };
        */
       
        //idea - 2
        string vowel = "aeiouAEIOU";
        unordered_set<char> st(begin(vowel), end(vowel));

        while(i<n/2 && j<n){
            if(st.find(s[i]) != st.end()){
                leftCount++;
            }

            if(st.find(s[j]) != st.end()){
                rightCount++;
            }
            i++;
            j++;
        }

        if(leftCount == rightCount){
            return true;
        }
        return false;
    }
};

int main() {
    string s = "book";
    //string s = "textbook";

    Solution sol;
    bool ans = sol.halvesAreAlike(s);

    cout << "Output: " << ans << endl;

    return 0;
}