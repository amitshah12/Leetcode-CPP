#include <iostream>
#include <vector>
using namespace std;

/*leetcode-118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
 
Constraints:
1 <= numRows <= 30
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pascal(numRows);

        for(int i=0; i<numRows; i++){
            pascal[i].resize(i+1);

            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
                }
            }
        }
        return pascal;
    }
};

int main() {
    int n;
    cout<<"Enter a number:";
    cin>>n;
    
    Solution sol;
    vector<vector<int>> ans = sol.generate(n);

    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout << " [";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
            if(j != ans[i].size() - 1){
                cout << ", ";
            }
        }
        cout << "]";
        if(i != ans.size() - 1){
            cout << ",";
            cout << "\n";
        }
    }
    cout << "]\n";

    return 0;
}