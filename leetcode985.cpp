#include <iostream>
#include <vector>
using namespace std;

//Method-1-brut force
// class Solution {
// public:
//     vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int q = queries.size();

//         vector<int> result;

//         for(int i = 0; i<q; i++){
//             int val = queries[i][0];
//             int idx = queries[i][1];

//             int evenSum = 0;
//             nums[idx] += val;
//             for(int j = 0; j<n; j++){
//                 if(nums[j] % 2 == 0){
//                     evenSum += nums[j];
//                 }
//             }
//             result.push_back(evenSum);
//         }
//         return result;
//     }
// };

//Method-2
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int evenSum = 0;
        for(int &x : nums){
            if(x % 2 == 0){
                evenSum += x;
            }
        }

        vector<int> result;

        for(int i = 0; i<q; i++){
            int val = queries[i][0];
            int idx = queries[i][1];

            if(nums[idx]%2 == 0){
                evenSum-= nums[idx];
            }

            nums[idx] += val;

            if(nums[idx]%2 == 0){
                evenSum += nums[idx];
            }

            result.push_back(evenSum);
        }
        return result;
    }
};


int main() {
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};

    Solution sol;
    vector<int> Output = sol.sumEvenAfterQueries(nums,queries);

    cout << "Output = {";
    for(int i = 0; i<Output.size(); i++){
        cout << Output[i];
        if(i<Output.size()-1){cout << ",";}
    }
    cout << "}";

    return 0;
}