#include <iostream>
#include <vector>
using namespace std;

/*Leetcode 33:Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

int getPivot(vector<int>& arr, int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;

    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid +1;
        } else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int binarySearch(vector<int>& arr, int s, int e, int key){
    int start = s;
    int end = e;

    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        
        if(key >arr[mid]){
            start = mid +1;
        } else {
            end =mid -1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k){
    int pivot = getPivot(arr, n);
    if(k >= arr[pivot] && k<= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    } else {
        return binarySearch(arr, 0, pivot-1, k);
    }
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    int size = arr.size();
    int key = 0;

    int result = findPosition(arr, size, key);

    cout << "Index of target is: " << result << endl;
    
    
    return 0;
}