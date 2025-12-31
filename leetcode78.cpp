#include <iostream>
#include <vector>
using namespace std;

/* leetcode-70 Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
class Solution
{
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude
        solve(nums, output, index + 1, ans);

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution sol;
    vector<vector<int>> output = sol.subsets(nums);

    cout << "output = [";
    for (int i = 0; i < output.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < output[i].size(); ++j)
        {
            cout << output[i][j];
            if (j < output[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < output.size() - 1)
            cout << ",";
    }
    cout << "]\n";

    return 0;
}