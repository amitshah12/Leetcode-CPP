#include <iostream>
using namespace std;


class Solution {
public:
    string makeGood(string s) {
        string result = "";

        //Method 1 loop
        // for(char &ch : s){
        //     if(result.size() > 0 && (ch - 32 == result.back() || ch + 32 == result.back())){
        //         result.pop_back();
        //     } else {
        //         result.push_back(ch);
        //     }
        // }

        for(int i = 0; i<s.length(); i++){
            if(result.size() > 0 && (s[i] - 32 == result.back() || s[i] + 32 == result.back())){
                result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};

int main() {
    string s = "leEeetcode";

    Solution sol;
    string Result = sol.makeGood(s);

    cout << "Great String : " << Result << endl;

    return 0;
}