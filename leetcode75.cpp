#include <iostream>
#include<vector>
using namespace std;

/* Leetcode 75: Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0
*/

//Method-1
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zeros= 0, ones = 0, twos= nums.size()-1;
//         while (ones <= twos) {
//             if (nums[ones] == 0) {
//                 swap(nums[ones], nums[zeros]);
//                 zeros++;
//                 ones++;
//             }
//             else if (nums[ones] == 1) {
//                 ones++;
//             }
//             else if (nums[ones] == 2) {
//                 swap(nums[ones], nums[twos]);
//                 twos--;
//             }
//         }    
//     }
// };

//Method-2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        for(int &num : nums){
            if(num == 0){
                count_0++;
            } else if(num == 1){
                count_1++;
            } else {
                count_2++;
            }
        }

        for(int i = 0; i<n; i++){
            if(count_0 > 0){
                nums[i] = 0;
                count_0--;
            } else if(count_1>0){
                nums[i] = 1;
                count_1--;
            } else if(count_2>0){
                nums[i] = 2;
                count_2--;
            }
        }
        
    }
};

int main() {
    vector<int> nums = {2,0,2,1,1,0};

    Solution sol;
    sol.sortColors(nums);

    cout << "Output = {" ;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i];
        if(i<nums.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}