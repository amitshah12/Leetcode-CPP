#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*Leetcode-3446. Sort Matrix By Diagonals
You are given an n x n square matrix of integers grid. Return the matrix such that:
The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
 
Example 1:
Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:
The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:
Input: grid = [[0,1],[1,2]]
Output: [[2,1],[1,0]]
Explanation:
The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.

Example 3:
Input: grid = [[1]]
Output: [[1]]
Explanation:
Diagonals with exactly one element are already in order, so no changes are needed.
Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
*/


//Approch-1 (Without Map - Simulation)
//T.C : O(n^2 * logn)
//S.C : O(n)
// class Solution {
// public:
//     int n;
    
//     void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
//         vector<int> vec; //diagonal elements starting from [r][c]

//         int i = r;
//         int j = c;

//         while(i < n && j < n) {
//             vec.push_back(grid[i][j]);
//             i++;
//             j++;
//         }

//         if(asc) {
//             sort(begin(vec), end(vec));
//         } else {
//             sort(rbegin(vec), rend(vec));
//         }

//         i = r;
//         j = c;
//         for(int &val : vec) {
//             grid[i][j] = val;
//             i++;
//             j++;
//         }
//     }

//     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
//         n = grid.size();

//         //Bottom Left - Non-Increasing Order
//         for(int row = 0; row < n; row++) {
//             sortDiagonal(row, 0, grid, false);
//         }


//         //Top Right - Non-Decreasing Order
//         for(int col = 1; col < n; col++) {
//             sortDiagonal(0, col, grid, true);
//         }

//         return grid;
        
//     }
// };


//Approach-2 (Using Map - (i-j) as the key)
//T.C : O(n^2 * logn)
//S.C : O(n^2) map stores all elements

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;
        //(i-j) -> diagonal elements

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                mp[diag].push_back(grid[i][j]);       
            }
        }

        for(auto &it : mp) {
            if(it.first >= 0) { //Key
                sort(begin(it.second), end(it.second));
            } else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();      
            }
        }

        return grid;
    }
};


int main() {
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};

    Solution sol;
    vector<vector<int>> output = sol.sortMatrix(grid);

    cout << "output = [";
    for (int i = 0; i < output.size(); ++i) {
        cout << "[";
        for (int j = 0; j < output[i].size(); ++j) {
            cout << output[i][j];
            if (j < output[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < output.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}