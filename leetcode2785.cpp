#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//
/*
class Solution {
public:
    string vowelStr(string s){
        string vowel = "";

        for(char ch : s){
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
               ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){

                vowel.push_back(ch);
            }
        }
        sort(begin(vowel), end(vowel));

        return vowel;
    }

    string sortVowels(string s) {
        int n = s.length();
        string vowel = vowelStr(s);

        int j = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || 
               s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){

                s[i] = vowel[j];
                j++;
           }
        }
        return s;
    }
};
*/

//Method - 2
/*
class Solution {
public:
    bool isvowel(char ch){
        ch = tolower(ch);

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        string temp = "";

        for(char ch : s){
            if(isvowel(ch)){
                temp.push_back(ch);
            }
        }
        sort(begin(temp), end(temp));

        int j = 0;
        for(int i=0; i<s.length(); i++){
            if(isvowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};
*/


class Solution {
public:
    bool isvowel(char ch){
        ch = tolower(ch);

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        unordered_map<char, int>freq;
        for(char ch : s){
            if(isvowel(ch)){
                freq[ch]++;
            }
        }

        string temp = "AEIOUaeiou";
        int j = 0;
        for(int i = 0; i<s.length(); i++){
            if(isvowel(s[i])){
                
                while(freq[temp[j]]==0){
                    j++;
                }
                s[i] = temp[j];
                freq[temp[j]]--;
            }
        }
        return s;
    }
};

int main() {
    string s = "lEetcOde";

    Solution sol;
    string ans = sol.sortVowels(s);

    cout << "Output: " << ans << endl;

    return 0;
}