#include <iostream>
using namespace std;


//method-1 brut force T(n) = O(h-l)
/*
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        
        for(int i = low; i<= high; i++){
            if(i % 2 != 0){
                count++;
            }
        }
        return count;
    }
};
*/

//Method-2 T(n)= O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        
        // If low is even, make it odd.
        if(low%2==0){
            low++;
        }
        if(high%2==0){
            high--;
        }
        return (high-low)/2 + 1;
    }
};

int main() {
    int low = 8, high = 10;

    Solution sol;
    int ans = sol.countOdds(low, high);

    cout << "No. of Odd = " << ans << endl;
    return 0;
}