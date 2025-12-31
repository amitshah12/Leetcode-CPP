#include <iostream>
#include <vector>
#include<stack>
using namespace std;

/*Leetcode-739. Daily Temperatures
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

//Method-1 Brut-force
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
        
//         vector<int>answer;
//         for(int i = 0; i<n; i++){
//             int count = 0;
//             for(int j = i+1; j<n; j++){
//                 if(temperatures[i] < temperatures[j]){
//                     count = j-i;
//                     break;
//                 }
//             }
//             answer.push_back(count);
//         }
//         return answer;
//     }
// };

//Method-2 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;

        vector<int>answer(n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()){
                answer[i] = 0;
            } else{
                answer[i] = st.top() - i;//days
            }
            st.push(i);
        }
        return answer;
    }
};

int main() {
    vector<int> tempetemperatures = {73,74,75,71,69,72,76,73};

    Solution sol;
    vector<int> ans = sol.dailyTemperatures(tempetemperatures);

    cout << "Output: {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i < ans.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}