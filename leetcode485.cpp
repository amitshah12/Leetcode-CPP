#include <iostream>
#include <vector>
using namespace std;
/**/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int i = 0;
        int j = 0;
        while(i<n && j<n){
            if(nums[i] == 1 && nums[j] == 1){
                count = max(count,j-i+1);
                j++;
            }else if(nums[j] != 1){
                j++;
                i = j;
            }
        }
        return count;
    }
};

int main() {
    vector<int>nums ={1,1,0,1,1,1};

    Solution sol;
    int ans = sol.findMaxConsecutiveOnes(nums);

    cout << "Output: " << ans << endl;
    
    return 0;
}