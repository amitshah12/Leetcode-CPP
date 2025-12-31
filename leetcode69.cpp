#include <iostream>
using namespace std;


/* Leetcode 69:Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/
int mySqrt(int x) {
    int start =0, end = x;

    long long int mid = start + (end - start)/2;
    long long int ans = -1;

    while(start<=end){

        long long int sqr = mid * mid;

        if(sqr == x){
            return mid;
        }

        if(sqr < x){
            ans = mid;
            start = mid + 1;
        } else {
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main() {
    int x = 1024;

    int square_root = mySqrt(x);
    cout << "Index of target is: " << square_root << endl;

    return 0;
}