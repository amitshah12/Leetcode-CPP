#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*Leetcode-16. 3SumCloset
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

// Method -1 brut Forcr T(n) = O(n^3)
//  class Solution {
//  public:
//      int threeSumClosest(vector<int>& nums, int target) {
//          int n = nums.size();

//         int bestSum = nums[0] + nums[1] +nums[2];
//         int bestDiff = abs(target-bestSum);

//         for(int i = 0; i<n; i++){
//             for (int j = i+1; j < n; j++){
//                 for(int k = j+1; k<n; k++){
//                     int sum = nums[i] + nums[j] +nums[k];
//                     int diff = abs(target-sum);

//                     if(diff<bestDiff){
//                         bestDiff = diff;
//                         bestSum = sum;
//                     }
//                 }
//             }
//         }
//         return bestSum;
//     }
// };

// Method - 2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 100000;

        //sort
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < abs(target-closestSum)){
                    closestSum = sum;
                }

                if(sum<target){
                    j++;
                } else {
                    k--;
                }
            }
        }
        return closestSum;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution sol;
    int ans = sol.threeSumClosest(nums, target);

    cout << "Sum of the 3 interger: " << ans << endl;
    return 0;
}