#include <iostream>
#include <stack>
using namespace std;

/*Leetcode-20. Valid Parentheses
*/

//Method-1

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char>st;

//         for(char ch : s){
//             if(st.empty() ||ch == '(' || ch == '{' || ch == '['){
//                 st.push(ch);
//                 continue;
//             }

//             if(ch == ')'){
//                 if(st.top() == '('){
//                     st.pop();
//                 } else{
//                     return false;
//                 }
//             } else if(ch == '}'){
//                 if(st.top() == '{'){
//                     st.pop();
//                 } else{
//                     return false;
//                 }
//             } else if(ch == ']'){
//                 if(st.top() == '['){
//                     st.pop();
//                 } else {
//                     return false;
//                 }
//             }
//         }
//         return st.empty();
//     }
// };

//Method-2
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(char &ch : s){
            if(ch == '('){
                st.push(')');
            } else if(ch == '{'){
                st.push('}');
            } else if(ch == '['){
                st.push(']');
            } else if(st.empty() || st.top() != ch){
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    //string s = "()";
    // string s = "(]";
    //string s = "()[]{}";
    string s = "[{(())}]";
    
    Solution sol;
    bool ans = sol.isValid(s);

    cout << "Output : " << ans;

    return 0;
}