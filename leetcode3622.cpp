#include <iostream>
using namespace std;

/*Leetcode-3622. Check Divisibility by Digit Sum and Product
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.

Example 1:
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:
Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

Constraints:
1 <= n <= 106
*/

//Method-1: Using digit sum and digit product functions
// class Solution {
// public:
//     int digit_sum(int n){
//         int sum = 0;

//         while(n>0){
//             int rem = n%10;
//             sum = sum + rem;
//             n = n/10;
//         }
//         return sum;
//     }

//     int digit_prod(int n){
//         int prod = 1;
//         while(n>0){
//             int rem = n%10;
//             prod = prod * rem;
//             n = n/10;
//         }
//         return prod;
//     }

//     bool checkDivisibility(int n) {
//         int sum = digit_sum(n);
//         int prod = digit_prod(n);

//         if( n % (sum+prod) == 0){
//             return true;
//         }
//         return false;
//     }
// };

// Method-2: Using single loop to calculate digit sum and digit product
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int temp = n;

        while(n>0){
            int rem = n%10;
            sum = sum + rem;
            prod = prod*rem;
            n = n/10;
        }

        if(temp % (sum+prod)==0){
            return true;
        }
        return false;
    }
};

int main() {
    int n = 99;
    // int n = 23;

    Solution sol;
    bool ans = sol.checkDivisibility(n);

    cout << "Output: " << ans << endl;

    return 0;
}