#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(); // Number of rows
        int cols = strs[0].size(); //Numbers of columns

        int deletion = 0;

        vector<bool> alreadySorted(rows, false);

        int row = 0;
        int col = 0;

        //to iterate in the strs

        for(int col = 0; col<cols; col++){
            bool deleted = false;

            for(row = 0; row < rows -1; row++){
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                    deletion++;
                    deleted = true;
                    break;
                }
            }

            if(deleted){
                continue;
            }

            for(int row = 0; row<rows-1; row++){
                alreadySorted[row] = alreadySorted[row] || (strs[row][col] < strs[row+1][col]);
            }
        }
        return deletion;
    }
};

int main() {
    //vector<string> strs = {"ca","bb","ac"};
    //vector<string> strs = {"xc","yb","za"};
    vector<string> strs = {"zyx","wvu","tsr"};

    Solution sol;
    int ans = sol.minDeletionSize(strs);

    cout << "Output : " << ans;

    return 0;
}