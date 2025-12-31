#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        vector<vector<int>> result;
        int minDiff = INT_MAX;

        for(int i = 1; i<n; i++){
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }

        for(int i = 1; i<n; i++){
            int diff = arr[i]-arr[i-1];

            if(diff == minDiff){
                result.push_back({arr[i-1], arr[i]});
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr = {4,2,1,3};

    Solution sol;
    vector<vector<int>> ans = sol.minimumAbsDifference(arr);

    cout << "ans = {";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ",";
        }
        cout << "}";
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << "}\n";

    return 0;
}