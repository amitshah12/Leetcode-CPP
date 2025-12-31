#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*Question-Sort a stack
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:
Input: st[] = [1, 2, 3]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103
*/

class Solution{
    public:
    void sortedInsert(stack<int> &st, int num){
        //base case
        if(st.empty() || (!st.empty() && st.top() < num)){
            st.push(num);
            return;
        }
        int n = st.top();
        st.pop();

        //recursive call
        sortedInsert(st,num);
        st.push(n);
    }
    void sortStack(stack<int> &st){
        //base case
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();

        sortStack(st);

        sortedInsert(st,num);
    }
};

int main() {
    vector<int> v = {1,2,3};
    stack<int> st;

    for(int n : v){
        st.push(n);
    }

    Solution sol;
    sol.sortStack(st);   
    
    cout << "Output : {";
    while(!st.empty()){
        cout << st.top();
        st.pop();
        if(!st.empty()){
            cout << ", ";
        }
    }
    cout << "}";

    return 0;
}