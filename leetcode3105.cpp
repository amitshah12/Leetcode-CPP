#include <iostream>
#include <vector>
using namespace std;

/*Leetcode 3105:Longest Strictly Increasing or Strictly Decreasing Subarray
You are given an array of integers nums. Return the length of the longest subarray of nums which is either 
strictly increasing or strictly decreasing.

Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest = 1;
        int strict_long = 1;
        int strict_small = 1;

        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                strict_long++;
            } else {
                strict_long = 1;
            }

            if(nums[i]<nums[i-1]){
                strict_small--;
            } else {
                strict_small = 1;
            }
            //longest = max({longest, strict_long, strict_small});
            longest = max(longest, max(strict_long, strict_small));
        }
        return longest;
        
    }
};

int main() {
    vector<int> arr = {1, 4, 3, 3, 2};
    
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution sol;
    int longest = sol.longestMonotonicSubarray(arr);

    cout << "Longest length is: "<< longest << endl;

    return 0;
}