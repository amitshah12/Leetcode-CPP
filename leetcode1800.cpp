#include <iostream>
#include <vector>
using namespace std;

/* Leetcode 1800 : Maximum Ascending Subarray Sum
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.
Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        int total_sum = sum;

        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                sum = sum + nums[i];
            } else {
                total_sum = max(total_sum,sum);
                sum = nums[i];
                // if(total_sum < sum){
                //     int total_sum = sum;
                //     sum = 0;
                // } else {
                //     return total_sum;
                // }
                
            }
        }
        total_sum = max(total_sum,sum);
        return total_sum;
    }
};

int main() {
    vector<int> arr = {10,20,30,40,50};
    //vector<int> arr = {10,20,30,5,10,50};
    
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution sol;
    int Max_Ascending_sum = sol.maxAscendingSum(arr);

    cout << "Longest length is: "<< Max_Ascending_sum << endl;
    return 0;
}