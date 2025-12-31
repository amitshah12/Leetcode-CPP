#include <iostream>
#include <vector>
using namespace std;
/*Leetcode-744. Find Smallest Letter Greater Than Target*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ch;
        for(int i = 0; i<n; i++){
            if(letters[i] > target){
                ch = letters[i];
                break;
            }else if(letters[i] < target){
                ch = letters[0];
            }
        }
        return ch;
    }
};

int main() {
    //vector<char> letters = {'c','f', 'j'};
    vector<char> letters = {'x','x', 'y', 'y'};
    char target = 'z';

    Solution sol;
    char ans = sol.nextGreatestLetter(letters,target);

    cout << "Output: " << ans << endl;

    return 0;
}