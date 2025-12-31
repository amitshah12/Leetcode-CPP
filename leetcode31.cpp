#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


/* leetcode 31-Next Permutation
nums permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
*/


//Method-1 Using cpp STL->This method is not adviced to do during interview as interviewer does not expect this

// class Solution{
//     public:
//     void nextPermutation(vector<int>& nums){
//         next_permutation(nums.begin(), nums.end());
//     }
// };


//Method-2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the pivot
        int pivot = -1, n = nums.size();

        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        //if pivot is not found i.e array is in decreasing order so make it in ascending order which will be next permutaion.
        if(pivot == -1){
            reverse(nums.begin(), nums.end());//in place changes
            return;
        }


        //2nd step: next larger element or right most element
        for(int i = n-1; i>pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //3rd step : reverse(Pivot + 1 to n-1)
        //reverse(A.begin() + pivot + 1, A.end());

        int i = pivot+1, j = n-1;
        while(i<=j){
            swap(nums[i++], nums[j--]);
        }
    }
};


int main() {
    vector<int> nums = {1,2,3};

    Solution sol;
    sol.nextPermutation(nums);

    cout << "[";
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i];
        if(i < nums.size()-1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}