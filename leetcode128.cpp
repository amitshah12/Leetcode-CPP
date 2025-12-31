#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*Leetcode-128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int longest = 0;

        for(int x : st){
            if(st.find(x-1) == st.end()){
                int curr = x;
                int len = 1;

                while(st.find(curr + 1) != st.end()){
                    curr++;
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};

    Solution sol;
    int ans = sol.longestConsecutive(nums);

    cout << "Output : " << ans << endl;

    return 0;
}