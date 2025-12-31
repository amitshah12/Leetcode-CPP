#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*Leetcode-912. Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
public:
    //Using Counting Sort
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));

        unordered_map<int,int>freq;
        for(int x : nums){
            freq[x]++;
        }

        int i = 0;
        for(int num = minE; num<=maxE; num++){
            
            while(freq[num]>0){
                nums[i] = num;
                i++;
                freq[num]--;
            }
        }
        return nums;
    }
};

int main() {
    // vector<int> nums = {5,2,3,1};
    vector<int> nums = {5,1,1,2,0,0};

    Solution sol;
    vector<int> ans = sol.sortArray(nums);

    cout << "Output: {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i<ans.size()-1){
            cout<<",";
        }
    } 
    cout << "}";

    return 0;
}