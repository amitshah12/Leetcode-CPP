#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        //XOR ing all array elements
        for(int i = 0; i<nums.size(); i++){
            ans == ans ^ nums[i];
        }
        
        //XOR[1,n-1]
        for(int i = 1; i<nums.size(); i++){
            ans = ans^i;
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}