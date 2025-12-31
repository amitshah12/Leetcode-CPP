#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

class Solution{
    public:
    vector<int> intersection(vector<int> nums1, vector<int>nums2){
        unordered_set<int>s(begin(nums1), end(nums1));
        unordered_set<int>result;

        for(auto x : nums2){
            if(s.count(x)){
                result.insert(x);
            }
        }
        return vector<int>(begin(result),end(result));
    }
};

int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution sol;
    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Output: {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i<ans.size()-1){
            cout << ",";
        }
    }
    cout << "}" << endl;
    
    return 0;
}