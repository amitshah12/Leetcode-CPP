#include <iostream>
#include <cmath>
using namespace std;

/*leetcode-231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-231 <= n <= 231 - 1
*/


class Solution {
public:

//Approach -1
    // bool isPowerOfTwo(int n) {
    //     if(n<=0){
    //         return false;
    //     }

    //     while(n>0){
    //         if(n==1){
    //             return true;
    //         }else if(n%2 == 0){
    //             n=n/2;
    //         } else {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    //Approach-2
    //T.C : O(log(n))
    //S.C : O(1)
    // bool isPowerOfTwo(int n){
    //     if(n <= 0){
    //         return false;
    //     }

    //     //base case
    //     if(n == 1){
    //         return true;
    //     }

    //     return n%2 == 0 && isPowerOfTwo(n/2);
    // }

    //Approach-3
    //T.C : O(1)
    //S.C : O(1)
    bool isPowerOfTwo(int n){
        return (n>0) && ((n & (n-1)) == 0);
    }

};

int main() {
    int n;
    cin>>n;

    
    Solution sol;
    bool Ans = sol.isPowerOfTwo(n);
    
    cout<<"Ans = "<< Ans;


    return 0;
}