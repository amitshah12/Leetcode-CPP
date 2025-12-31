#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*Leetcode - 3512:Minimum Operations to Make Array Sum Divisible by K

You are given an integer array nums and an integer k. You can perform the following operation any number of times:

Select an index i and replace nums[i] with nums[i] - 1.
Return the minimum number of operations required to make the sum of the array divisible by k.

Example 1:
Input: nums = [3,9,7], k = 5
Output: 4
Explanation:
Perform 4 operations on nums[1] = 9. Now, nums = [3, 5, 7].
The sum is 15, which is divisible by 5.
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //return accumulate(nums.begin(), nums.end(),0) % k;
        return accumulate(begin(nums), end(nums),0) % k;
    }
};

int main() {
    //vector<int> nums = {3,9,7};
    //int k = 5;
    
    vector<int> nums = {3,2};
    int k = 6;

    Solution sol;
    int ans = sol.minOperations(nums,k);

    cout << "No. of operation = " << ans;
    
    return 0;
}