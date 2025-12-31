#include <iostream>
#include <vector>
using namespace std;
/* Coding Ninjas : https://bit.ly/3y01Zdu

Problem statement: You have given an interger array/list (ARR) of size N. Where N is equal to [2M+1].

Now, in the given array/list, 'M' numbers are presented twice and one number is presented only once.
You need to find and returns that numbers which is unique in the array/list.

Note: Unique element is always present in the array/list according to the given condition.
*/
int findUnique(int *arr, int size){
    int ans = 0;

    for(int i=0; i<size; i++){
        ans = ans ^arr[i];
    }
    return ans;
}

/* Leetcode: 540. Single Element in a Sorted Array

problem statement: 
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            
            //using XOR operation-it returns 0 when performed between itself
            ans = ans ^ nums[i]; //XOR gives 0 between same input and gives 1 with different
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}