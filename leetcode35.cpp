#include <iostream>
#include <vector>
using namespace std;

/*leetcode-35 : Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        //Method -1 T(n) = O(log n)
        int low = 0; 
        int high = nums.size();

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                return mid;
            } else if(nums[mid]<target){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return low;

        //Method-2 T(n) = O(n)
        /*
        int i = 0;
        while(i<nums.size()){
            if(nums[i] == target){
                return i;
            } else {
                if(nums[i]<target){
                    i++;
                } else if(nums[i]>target){
                    return i;
                }
            }
        }
        return i;
        */
    }
};

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 5;

    Solution sol;
    int ans = sol.searchInsert(nums, target);

    cout << "Index is " << ans << endl;

    return 0;
}