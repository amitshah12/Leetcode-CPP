#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*leetcode-53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Using Kedane's Algorithm
        int currSum = 0, maxSum = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution sol;
    int ans = sol.maxSubArray(nums);

    cout << "Output : " << ans << endl;

    return 0;
}