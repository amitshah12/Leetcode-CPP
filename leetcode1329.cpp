#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();//no. of rows
        int n = mat[0].size();//no. of cols

        unordered_map<int, vector<int>>mp;

        //storing diagonal element in map
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        //sort them
        for(auto &it : mp){
            sort(it.second.begin(), it.second.end());
        }

        //now collect sorted result
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};

int main() {
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

    Solution sol;
    vector<vector<int>> ans = sol.diagonalSort(mat);

    cout<< "output: " << endl;
    return 0;
}