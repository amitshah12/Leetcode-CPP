#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*Leetcode-219. Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 
Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

//Method-1-Brut Force T(n) = O(n^2) exceed time limit for larger array
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();

//         for(int i = 0; i<n-1; i++){
//             for(int j = i+1; j<n; j++){
//                 if(nums[i] == nums[j] && abs(i-j)<=k){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


//Method -2

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++){
            if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]]-i) <= k){ //check if present in map and abs(i-j)<= k
                return true;
            } else {
                mp[nums[i]] = i;//{number, index}
            }
        }
        return false;
    }
};


int main() {
    // vector<int> nums = {1,2,3,1};
    // int k = 3;
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    Solution sol;
    bool ans = sol.containsNearbyDuplicate(nums,k);

    cout << "Output : " << ans << endl;

    return 0;
}