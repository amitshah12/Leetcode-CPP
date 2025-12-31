#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
    
        int result = 0;
        for (int i = 0; i < 32; i++) {
            // result <<= 1;
            result = result << 1;
            

            result = (result | (n & 1));
            
            // n >>= 1;
            n = n >> 1;
        }

        return result;
    }
};

int main() {
    // int n = 43261596;
    int n = 58;

    Solution sol;
    int ans = sol.reverseBits(n);

    cout << "Output : " << ans;

    return 0;
}