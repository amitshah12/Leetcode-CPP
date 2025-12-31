#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        int mCount = 1;
        int count = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                count++;
            } else {
                count = 1;
            }
            mCount = max(mCount, count);
        }
        return mCount;
    }
};

int main() {
    vector<int> nums = {1,3,5,4,7};
    Solution sol;
    int ans = sol.findLengthOfLCIS(nums);

    cout << "Output : " << ans << endl;
    
    return 0;
}