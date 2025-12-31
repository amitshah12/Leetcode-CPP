#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcdoe-1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

//Approach-1-Using recursion memoization
/*
class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t){
        if(i>=m || j>=n){
            return 0;
        }

        if(matrix[i][j] == 0){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int right = solve(i, j+1, matrix, t);
        int diag = solve(i+1, j+1, matrix, t);
        int below = solve(i+1, j, matrix, t);
        
        return t[i][j] = 1 + min({right, diag, below});

    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int result = 0;//total numeber of square submatrixs having only 1s
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 1){
                    result += solve(i,j,matrix, t);
                }
            }
        }
        return result;
    }
};
*/
//


//Approch-2 - using bottom up
class Solution{
    public:
    int countSquares(vector<vector<int>>& matrix){
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        int result = 0; //total number of square submatrixes having only 1s

            

        //t[i][j] = total square submatrices (having 1s) ending at cell [i][j]

        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                if(i==0 || j==0){ //0th row or 0th column
                    t[i][j] = matrix[i][j];
                } else if(matrix[i][j] == 1){
                    t[i][j] = 1 + min({t[i-1][j], t[i-1] [j-1], t[i][j-1]});
                }
                result += t[i][j];
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{0,1,1,1},
                                   {1,1,1,1},
                                   {0,1,1,1}};

    Solution sol;
    int output = sol.countSquares(matrix);

    cout<<"Output = "<< output << endl;

    return 0;
}