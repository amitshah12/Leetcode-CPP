#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*leetcode-1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

//Approach-1- Using brutforce
// class Solution {
// public:
//     int n;

//     int findMax(vector<int>& nums, int skip_idx){
//         int curLength = 0;
//         int maxLength = 0;

//         for(int i = 0; i<n; i++){
//             if(i==skip_idx){
//                 continue;
//             }

//             if(nums[i] == 1){
//                 curLength++;
//                 maxLength = max(maxLength, curLength);
//             } else {
//                 curLength = 0;
//             }
//         }
//         return maxLength;
//     }

//     int longestSubarray(vector<int>& nums) {
//         n = nums.size();

//         int result = 0;
//         int countZero = 0;
        
//         for(int i = 0; i<n; i++){
//             if(nums[i]==0){
//                 countZero++;
//                 result = max(result, findMax(nums, i));
//             }
//         }

//         if(countZero == 0){
//             return n-1;
//         }


//         return result;
//     }
// };

//Approach-2-using sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxLength = 0;

        int i = 0;
        for(int j = 0; j<nums.size(); j++){
             if(nums[j] == 0){
                zeroCount++;
             }

             while(zeroCount > 1){
                if(nums[i]==0){
                    zeroCount--;
                }
                i++;
             }
             maxLength = max(maxLength, j-i);
        }
        return maxLength;
    }
};

//Approach-3
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int i = 0;
//         int j = 0;

//         int last_zero_idx = 0;

//         int result = 0;
//         while(j<nums.size()){
//             if(nums[j] == 0){
//                 i = last_zero_idx + 1;
//                 last_zero_idx = j;
//             }
//             result = max(result, j-1);
//             j++;
//         }
//         return result;
//     }
// };

int main() {
    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    Solution sol;
    int output = sol.longestSubarray(nums);

    cout<<"Output = " << output << endl;


    return 0;
}