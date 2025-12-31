#include <iostream>
#include<vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* leetcode: 1207. Unique Number of Occurrences
 Problem statement: 
 Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
*/


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq; // To store frequencies of each element

    // Count occurrences of each element
    for (int num : arr) {
        freq[num]++;
    }

    // Use a set to track unique frequencies
    unordered_set<int> uniqueFreq;
    for (auto it : freq) {
        if (uniqueFreq.find(it.second) != uniqueFreq.end()) {
            return false; // Duplicate frequency found
        }
        uniqueFreq.insert(it.second);
    }

    return true;
    }
};

int main(){

    return 0;

}