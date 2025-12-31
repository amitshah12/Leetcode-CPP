#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//Method -1-Brute Force T(n) = O(n^3)
// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();

//         if(n<3){
//             return false;
//         }

//         for(int i = 0; i<n-2; i++){
//             for(int j = i+1; j<n-1; j++){
//                 if(nums[i]<nums[j]){
//                     for(int k = j+1; k<n; k++){
//                         if(nums[j]<nums[k]){
//                             return true;
//                         }
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for(int i=0; i<n; i++){
            int num3 = nums[i];

            if(num3 <= num1){
                num1 = num3;
            } else if(num3 <= num2){
                num2 = num3;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};

    Solution sol;
    bool ans = sol.increasingTriplet(nums);

    cout << "Output: " << ans << endl;

    return 0;
}