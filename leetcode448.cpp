#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*448. Find All Numbers Disappeared in an Array
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
 
Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int>st;

        for(int x : nums){
            st.insert(x);
        }

        vector<int>result;
        for(int i = 1; i<=n; i++){
            if(st.find(i) == st.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution sol;
    vector<int>ans = sol.findDisappearedNumbers(nums);

    cout<< "Output : {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i<ans.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}