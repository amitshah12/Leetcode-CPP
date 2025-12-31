#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Method -1
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();

//         map<int, int>mp;
//         for(int x : nums){
//             mp[x]++;
//         }

//         int dup = 0, mis = 0;
//         for(int i = 1; i<=n; i++){
//             if(mp[i] == 2){
//                 dup = i;
//             } else if(mp[i] == 0){
//                 mis = i;
//             }
//         }

//         return {dup, mis};
//     }
// };

//Method-2
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int dup = -1;
        int miss = -1;

        for(int i = 0; i<n; i++){
            if(nums[abs(nums[i])-1] < 0){
                dup = abs (nums[i]);
            } else {
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }

        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                miss = (i+1);
                break;
            }
        }
        
        return {dup, miss};
    }
};

int main() {
    vector<int> nums = {1,2,2,4};

    Solution sol;
    vector<int> ans = sol.findErrorNums(nums);

    cout << "Output: {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i<ans.size()-1){
            cout << ",";
        }
    }
    cout << "}"<< endl;
    
    return 0;
}