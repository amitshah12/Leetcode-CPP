#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*leetcode-221. Maximal Square
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;

        vector<vector<int>> t(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) { // 0th row or 0th column
                    t[i][j] = matrix[i][j] =='0' ? 0 : 1;
                } else if (matrix[i][j] == '1') {
                    t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
            result = max(result, t[i][j]);
            }
        }
        return result * result;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};

    Solution sol;
    int output = sol.maximalSquare(matrix);

    cout<<"Output : " << output << endl;

    return 0;
}