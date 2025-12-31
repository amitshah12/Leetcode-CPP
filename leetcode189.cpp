#include <iostream>
#include <vector>
using namespace std;

/*Leetcode 189: Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        for(int i=0; i<nums.size(); i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums = temp;
    }    
};

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> v = {1,2,3,4,5,6,7};

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);

    //vector<int> ans = rotate(v, 3);
    Solution sol;
    sol.rotate(v,3);

    cout << "Printing rotated array Array: " << endl;
    print(v);
    
    return 0;
}