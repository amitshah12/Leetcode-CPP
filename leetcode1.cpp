#include <iostream>
#include <cstdlib>  // For malloc and free
using namespace std;

/*Leetcode 1 : Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    cout << "Output: { ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i < ans.size() - 1) cout << ", ";
    }
    cout << " }" << endl;

    return 0;
}
