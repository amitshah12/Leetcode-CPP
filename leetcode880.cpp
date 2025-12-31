#include <iostream>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long size = 0;

        for(char ch : s){
            if(isdigit(ch)){
                size = size * (ch-'0');
            } else {
                size++;
            }
        }

        for(int i = n-1; i>=0; i--){
            k = k % size;

            if(k == 0 && isalpha(s[i])){
                return string(1,s[i]); //returns a string of length 1, containing the character s[i]
            }

            if(isalpha(s[i])){
                size--;
            } else {
                size = size / (s[i]-'0');
            }
        }
        return "";
    }
};

int main() {
    string s = "leet2code3";
    int k = 10;

    Solution sol;
    string ans = sol.decodeAtIndex(s,k);

    cout << "Output : " << ans << endl;
}