#include <iostream>
#include <vector>
using namespace std;

/* Leetcode 410 : Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/
class Solution {
    bool isPossible(vector<int> arr, int n, int k, int mid){
        int count = 1;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            } else {
                count++;
                if(count > k || arr[i] > mid){
                    return false;
                }
                sum = arr[i];
            }
        }
        return true;
    }
    public:
        int splitArray(vector<int>& nums, int k) {
            int start = 0;
            int sum = 0;
            int n = nums.size();

            for(int i = 0; i<n; i++){
                sum += nums[i];
            }
            int end = sum;
            int ans = -1;

            int mid = start + (end-start)/2;
            while(start<=end){
                if(isPossible(nums,n,k,mid)){
                    ans =  mid;
                    end = mid -1;
                } else {
                    start = mid + 1;
                }
                mid = start + (end-start)/2;
            }
            return ans;
        }
    };
int main() {
    //vector<int> arr = {7, 2, 5, 10, 8}; 
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    Solution sol;
    cout << "Minimum largest sum: " << sol.splitArray(arr, k) << endl;
    return 0;
}