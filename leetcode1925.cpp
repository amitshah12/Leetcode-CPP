#include <iostream>
#include <cmath>
using namespace std;

/*1925. Count Square Sum Triples
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Example 1:
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:
Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 
Constraints:
1 <= n <= 250
*/

//Method-1 Brut force where T(n) = O(n^3)

// class Solution {
// public:
//     int countTriples(int n) {
//         int count=0;

//         for(int i = 1; i<=n; i++){
//             for(int j = i+1; j<=n; j++){
//                 for(int k = j+1; k<=n; k++){
//                     if((i*i) + (j*j) == (k*k)){
//                         count += 2;
//                     }

//                 }
//             }
//         }
//         return count;
//     }
// };

//Method-2 where T(n) = O(n^2)
class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                int s = i*i + j*j;
                int x = sqrt(s);
                if(x*x == s && x<=n){
                    count+=2;
                }
            }
        }
        return count;
    }
};


int main() {
    int n = 10;

    Solution sol;
    int ans = sol.countTriples(n);

    cout << "No. of square triple is " << ans << endl;

    return 0;
}