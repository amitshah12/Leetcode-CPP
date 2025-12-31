#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Method-1
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums, int k) {
//         int n = nums.size();
//         int minDiff = INT_MAX;

//         sort(begin(nums), end(nums));

//         int i = 0;
//         int j = k-1;
//         while(j<n){
//             int minEl = nums[i];
//             int maxEl = nums[j];

//             minDiff = min(minDiff, maxEl-minEl);

//             i++;
//             j++;
//         }
//         return minDiff;

//     }
// };

//Method-2
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int minDiff = INT_MAX;

        sort(begin(nums), end(nums));

        for(int i = k-1; i<n; i++){
            int minEl = nums[i-k+1];
            int maxEl = nums[i];

            minDiff = min(minDiff, maxEl - minEl);
        }
        return minDiff;

    }
};

int main() {
    vector<int> nums = {9,4,1,7};
    int k = 2;

    Solution sol;
    int ans = sol.minimumDifference(nums, k);

    cout << "Output : " << ans << endl;

    return 0;
}