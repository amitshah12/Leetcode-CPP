#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*Leetcode-229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
 
Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/

//Method -1 T(n) = O(n)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>freq;
//         for(int x : nums){
//             freq[x]++;
//         }

//         vector<int>result;
//         for(auto it : freq){
//             if(it.second > n/3){
//                 result.push_back(it.first);
//             }
//         }
//         return result;
//     }
// };

//Method-2
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;

        for(int num : nums){
            if(num == num1){
                count1++;
            } else if(num == num2){
                count2++;
            } else if(count1 == 0){
                num1 = num;
                count1 = 1;
            } else if(count2 == 0){
                num2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for(int num : nums){
            if(num == num1){
                count1++;
            } else if (num == num2){
                count2++;
            }
        }

        vector<int>result;
        if(count1 > n/3) result.push_back(num1); 
        if(count2 > n/3) result.push_back(num2); 

        return result;
    }
};

int main() {
    // vector<int> nums = {3,2,3};
    vector<int> nums = {5,2,3,2,2,2,2,5,5,5};

    Solution sol;
    vector<int> ans = sol.majorityElement(nums);

    cout << "Output : {";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i<ans.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}