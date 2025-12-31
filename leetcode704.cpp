#include <iostream>
#include<vector>
using namespace std;

/* leetcode-704. Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 
Constraints:
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

class Solution {
public:

    int binarySearch(vector<int>&nums, int s, int e, int target){
        //int s=0, e = nums.size();

        //base case
        if(s>e){
            return -1;
        }

        int mid = s + (e-s)/2;
        //element found
        if(target == nums[mid]){
            return mid;
        }

        //processing
        if(target>nums[mid]){
            int index = binarySearch(nums, mid+1, e, target);
            return index;
        } else {
            int index = binarySearch(nums, s, mid-1, target);
            return index;
        }
    }

    int search(vector<int>& nums, int target) {
        int ans = binarySearch(nums, 0, nums.size()-1, target);
        return ans;
    }
};

int main() {
    vector<int> nums= {-1,0,3,5,9,12};
    int size = nums.size();

    //int s=0, e = size-1;

    int target = 2;

    Solution sol;
    int Ans = sol.search(nums, target);
    cout<<"The index of the target is: "<< Ans <<endl;

    return 0;
}