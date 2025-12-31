#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>prime;

        for(int x : nums){
            for(int i = 2; i * i <=x; i++){
                while(x % i == 0){
                    prime.insert(i);
                    x /= i;
                }
            }
            if(x>1){
                prime.insert(x);
            }
        }
        return prime.size();
    }
};

int main() {
    // vector<int> nums = {2,4,3,7,10,6};
    vector<int> nums = {2,4,8,16};

    Solution sol;
    int ans = sol.distinctPrimeFactors(nums);

    cout << "Output: " << ans << endl;
    return 0;
}