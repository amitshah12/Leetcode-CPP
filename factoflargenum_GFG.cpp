#include <iostream>
#include <vector>
using namespace std;

/*Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

Examples:
Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120

Input: n = 10
Output: [3, 6, 2, 8, 8, 0, 0]
Explanation: 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Input: n = 1
Output: [1]

Explanation: 1! = 1 
Constraints:
1 ≤ n ≤ 103
*/

// User function template for C++
class Solution {
  public:
    
    void multiply(vector<int>& nums, int& size, int &multiplier){
        int carry = 0;
        
        for(int i = 0; i< size; i++){
            int result = (multiplier * nums[i]) + carry;
            
            nums[i] = result % 10;
            
            carry = result / 10;
        }
        
        while(carry>0){
            nums[size] = carry % 10;
            size++;
            carry /= 10;
        }
    }
    
    vector<int> factorial(int N) {
        // code here
        vector<int> nums(10000, 0);
        nums[0] = 1;
        int size = 1;
        int fact = N;
        
        for(int multiplier = 2; multiplier <= fact; multiplier++){
            multiply(nums, size, multiplier);
        }
        
        vector<int> result;
        for(int i = size-1; i>=0; i--){
            result.push_back(nums[i]);
        }
        return result;
        
    }
};

int main() {
    int  N = 100;

    Solution sol;
    vector<int> ans = sol.factorial(N);

    cout << "Factorial is: {";
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i];
        if(i < ans.size()-1) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}