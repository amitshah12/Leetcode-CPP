#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//Method-1
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int i = 0;

//         while(i < intervals.size()){
//             if(intervals[i][1] < newInterval[0]){
//                 i++;
//             } else if(intervals[i][0] > newInterval[1]){
//                 intervals.insert(intervals.begin() + i, newInterval);
//                 return intervals;
//             } else {
//                 //Overlap : merge them and erase the intervals which was merged
//                 newInterval[0] = min(newInterval[0], intervals[i][0]);
//                 newInterval[1] = max(newInterval[1], intervals[i][1]);
//                 intervals.erase(intervals.begin()+i);
//             }
//         }
//         intervals.push_back(newInterval);
//         return intervals;
        
//     }
// };

//Method-2
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        
        vector<vector<int>> result;
        int n = intervals.size();

        while(i<n){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            } else if(intervals[i][0] > newInterval[1]){
                break;
            } else {
                //merge and look ahead
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        result.push_back(newInterval);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    Solution sol;
    vector<vector<int>> ans = sol.insert(intervals, newInterval);

    cout << "Output = [";
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