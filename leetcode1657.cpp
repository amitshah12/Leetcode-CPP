#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        if(m != n){
            return false;
        }

        vector<int>freq1(26);
        vector<int>freq2(26);


        //Update frequency of char both in word1 and word2
        for(int i = 0; i<m; i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';

            freq1[idx1]++;
            freq2[idx2]++;
        }

        //check char present in word1 are present in word2 or not
        for(int i=0; i<26; i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;

            if(freq1[i] == 0 && freq2[i] == 0) continue;

            return false;
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return freq1 == freq2;
    }
};

int main() {
    // string word1 = "cabbba";
    // string word2 = "abbccc";

    string word1 = "a";
    string word2 = "aa";

    Solution sol;
    bool ans = sol.closeStrings(word1, word2);

    cout << "Output: " << ans << endl;

    return 0;
}