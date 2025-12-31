#include <iostream>
#include <vector>
using namespace std;

/*leetcode 283: Moves Zeros
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {

            int nonZero = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != 0) {
                    swap(nums[j], nums[nonZero]);
                    nonZero++;
                }
            }
    }
};

void print(vector<int>& ans, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0,1,0,3,12};

    Solution sol;
    sol.moveZeroes(nums);

    print(nums, nums.size());

    return 0;
}