#include <iostream>
#include <vector>
using namespace std;

//Method - 1
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for(int x : nums){

            int count = 0;
            int currSum = 0;

            for(int d = 1; d*d<=x; d++){
                if(x % d == 0){
                    int div1 = d;
                    int div2 = x / d;

                    count++;
                    currSum += div1;

                    if(div1 != div2){
                        count++;
                        currSum +=div2;
                    }

                    if(count>4){
                        break;
                    }
                }
            }
            if(count == 4){
                totalSum += currSum;
            }
        }
        return totalSum;
    }
};
int main() {
    //vector<int> nums = {21,4,7};
    vector<int> nums = {1,2,3,4,5};

    Solution sol;
    int ans = sol.sumFourDivisors(nums);

    cout << "Output: " << ans;
    return 0;
}