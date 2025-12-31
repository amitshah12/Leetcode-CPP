#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*leetcode-976. Largest Perimeter Triangle
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        for(int i = n-3; i>=0; i--){
            //nums[i]<nums[i+1]<nums[i+2]
            if(nums[i]+nums[i+1]>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];//a+b>c
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {2,1,2};
    //vector<int> nums = {1,2,1,10};

    Solution sol;
    int ans =  sol.largestPerimeter(nums);

    cout << "Output: " << ans << endl;
    
    return 0;
}