#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*Question-Reverse a Stack
You are given a stack st[]. You have to reverse the stack.

Note: The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

Examples:
Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

Constraints:
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100
*/

class Solution {
  public:
    void insertAtBottom(stack<int> &st, int element){
        //base case
        if(st.empty()){
            st.push(element);
            return;
        }
        int num = st.top();
        st.pop();
        
        //recursive call
        insertAtBottom(st,element);
        st.push(num);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();
        
        //recursive call
        reverseStack(st);
        
        insertAtBottom(st, num);
    }
};

int main() {
    vector<int> v = {1,2,3,4};
    stack<int> s;

    for(int n : v){
        s.push(n);
    }

    Solution sol;
    sol.reverseStack(s);   
    
    cout << "Output : {";
    while(!s.empty()){
        cout << s.top();
        s.pop();
        if(!s.empty()){
            cout << ", ";
        }
    }
    cout << "}";

    return 0;
}