#include <iostream>
#include <vector>
using namespace std;

/*Leetcode 3151:Special Array I
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Example 1:
Input: nums = [1]
Output: true
Explanation:
There is only one element. So the answer is true.

Example 2:
Input: nums = [2,1,4]
Output: true
Explanation:
There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.
*/
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0; i < nums.size()-1; i++){
            if(nums[i]%2 == nums[i+1]%2){
                return false;
            } 
        }
        return true;
    }
};

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};    
    //vector<int> arr = {4,3,1,6};    
    //vector<int> arr = {2,1,4};

    Solution sol;
    int result = sol.isArraySpecial(arr);

    cout << "Is given array special?" << (result ? "Yes" : "No") << endl;

    return 0;
}