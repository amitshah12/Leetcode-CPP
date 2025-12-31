#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

/*
leetcode-1394:Find Lucky Integer in an Array
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

Example 2:
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

Example 3:
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
*/

//Mehod-1
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (int x : arr) mp[x]++;

        int luckyInt = -1;
        for (auto &p : mp) {
            int num = p.first;
            int freq = p.second;
            if (freq == num) luckyInt = max(luckyInt, num);
        }
        return luckyInt;
    }
};

//Method-2
// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         if (arr.empty()) return -1;

//         sort(arr.begin(), arr.end());   // Group equal numbers together.

//         int lucky = -1;
//         int n = arr.size();
//         int i = 0;

//         while (i < n) {
//             int num = arr[i];
//             int j = i;

//             // Count how many times num appears.
//             while (j < n && arr[j] == num) {
//                 j++;
//             }
//             int freq = j - i;

//             // Lucky condition: value == its frequency (and value > 0; zero/neg can't be lucky).
//             if (num > 0 && freq == num) {
//                 lucky = max(lucky, num);
//             }

//             i = j; // Move to next distinct number.
//         }
//         return lucky;
//     }
// };

int main() {

    int n;
    cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arr(n);

    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }

    Solution sol;
    int ans = sol.findLucky(arr);
    cout<<"Ans = "<< ans;

    return 0;
}