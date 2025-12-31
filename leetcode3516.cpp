#include <iostream>
//#include <cstdlib>
//#include <bits/stdc++.h>
using namespace std;

/*Leetcode-3516. Find Closest Person

*/

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z-x);
        int b = abs(z-y);
        
        if(a == b){
            return 0;
        } else if(a < b){
            return 1;
        } else {
            return 2;
        }

    }
};

int main() {
    //int x = 2, y = 7, z = 4;
    int x = 2, y = 5, z = 6;

    Solution sol;
    int output = sol.findClosest(x, y, z);

    cout << "Output = " << output << endl;
    
    return 0;
}