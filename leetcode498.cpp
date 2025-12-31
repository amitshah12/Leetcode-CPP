#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*Leetcode-498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
*/
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> result;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (flip)
            {
                reverse(it->second.begin(), it->second.end());
            }

            for (int i = 0; i < it->second.size(); i++)
            {
                result.push_back(it->second[i]);
            }

            flip = !flip;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution sol;
    vector<int> output = sol.findDiagonalOrder(mat);

    cout << "Output = [";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
        if (i < output.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}