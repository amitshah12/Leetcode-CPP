#include <iostream>
#include <vector>
using namespace std;

/*leetcode -1662. Check If Two String Arrays are Equivalent

*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string w1 = "";
        string w2 = "";

        for(int i = 0; i<word1.size(); i++){
            w1 += word1[i];
        }

        for(int i = 0; i<word2.size(); i++){
            w2 += word2[i];
        }

        if(w1 == w2){
            return true;
        }

        return false;
    }
};

int main() {
    //
    // vector<string> word1 = {"ab", "c"};
    // vector<string> word2 = {"a", "bc"};
    
    vector<string> word1 = {"a", "cb"};
    vector<string> word2 = {"ab", "c"};

    Solution sol;
    bool ans = sol.arrayStringsAreEqual(word1, word2);

    cout << "Output: " << ans << endl;

    return 0;
}