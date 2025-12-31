#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Method-1
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            if(countA == countB)
                return a < b;   // sort by value if bits equal
            return countA < countB;
        });
        
        return arr;
    }
};

//method-2
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         map<int, vector<int>> mp;
        
//         // Group numbers by set bit count
//         for(int x : arr){
//             int bits = __builtin_popcount(x);
//             mp[bits].push_back(x);
//         }
        
//         vector<int> ans;
        
//         // Traverse map (bit count in ascending order)
//         for(auto &p : mp){
//             // Sort numbers with same bit count
//             sort(p.second.begin(), p.second.end());
            
//             // Add to result
//             for(int num : p.second){
//                 ans.push_back(num);
//             }
//         }
        
//         return ans;
//     }
// };

int main() {
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    Solution sol;
    vector<int>ans = sol.sortByBits(arr);

    cout << "Output : {";
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i];
        if(i<ans.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}