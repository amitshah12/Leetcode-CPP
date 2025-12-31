#include <iostream>
using namespace std;

// Function to check if a number is prime or not
class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        
        for(int i = 3; i * i <= n; i+=2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 5;

    Solution sol;
    bool ans = sol.isPrime(n);

    cout <<"Ouptput: " << ans << endl;

    return 0;
}