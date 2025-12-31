#include <iostream>
using namespace std;

/*Leetcode - 3345. Smallest Number With Given Digit Product
You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16

Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

Constraints:
1 <= n <= 100
1 <= t <= 10

*/
class Solution {
    int findDigitProd(int n){
        int prod = 1;
        
        while(n>0){
            prod = prod * (n % 10);
            n = n / 10;
        }
        return prod;
    }
    
    public int smallestNumber(int n, int t) {
        for(int num = n; num <= num+10; num++){
            if(findDigitProd(num) % t == 0){
                return num;
            }
        }
        return -1;
    }
}

int main() {
    int n = 10;
    int t = 2;

    Solution sol;
    int ans = sol.smallestNumber(n, t);

    cout << "The smallest number greater than or equal to " << n << " whose digit product is divisible by " << t << " is: " << ans << endl;


    return 0;
}