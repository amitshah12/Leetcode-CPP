#include <iostream>
#include <stack>
using namespace std;

//Method-1
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string result = "";

//         for(char s[i] : s){
//             if(result.empty() || result.back() != s[i]){
//                 result.push_back(s[i]);
//             } else if(result.back() == s[i]){
//                 result.pop_back();
//             }
//         }
//         return result;
//     }
// };

//Method-2
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string result = "";

        for(int i = s.length()-1; i>=0; i--){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            } else {
                st.pop();
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    string s = "abbaca";

    Solution sol;
    string ans = sol.removeDuplicates(s);

    cout << "Output : " << ans;
    
    return 0;
}