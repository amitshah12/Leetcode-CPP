#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* leetcode-15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the ans and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 
Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int low, int high){
        //low = 0;
        //high = nums.size()-1;
        int sum = 0;

        while(low<high){
            sum = nums[low] + nums[high];

            if(sum < target){
                low++;
            } else if(sum > target){
                high--;
            } else {
                //return {low+1, high+1};
                //first we will remove duplicate from either end(low,high)
                while(low<high && nums[low] == nums[low+1]) low++;

                while(low<high && nums[high] == nums[high-1]) high--;

                result.push_back({-target, nums[low], nums[high]});

                low++;
                high--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if(n<3){
            return {};
        }
        result.clear();

        //sort
        sort(begin(nums), end(nums));

        //fixing one element : n1
        for(int low = 0; low<n; low++){
            if(low>0 && nums[low] == nums[low-1]){
                continue;
            }
            int n1 = nums[low];
            int target = -n1;

            twoSum(nums, target, low+1, n-1); // it will find n2 and n3 : {n1, n2, n3}

        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    //vector<int> nums = {0,1,1};
    //vector<int> nums = {0,0,0};

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "ans = [";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << "]\n";

    return 0;
}