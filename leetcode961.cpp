#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//Method-1
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;

        unordered_map<int,int>mp;

        for(int x : nums){
            mp[x]++;
        }

        for(const auto& pair : mp){
            if(pair.second == n){
                return pair.first;
            }
        }
        return -1;
    }
};

//Method-2-Optimized T(n)
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_set<int>st;

//         for(int x : nums){
//             if(st.count(x)){
//                 return x;
//             }
//             st.insert(x);
//         }
//         return -1;
//     }
// };

int main() {
    //vector<int> nums = {1,2,3,3};
    vector<int> nums = {5,1,5,2,5,3,5,4};

    Solution sol;
    int ans = sol.repeatedNTimes(nums);

    cout << "Output: " << ans << endl;

    return 0;
}