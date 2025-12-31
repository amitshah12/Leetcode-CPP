#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);

        for(char &ch : sentence){
            int index = ch - 'a';
            arr[index]++;
        }

        for(int &count : arr){
            if(count == 0){
                return false;
            }
        }

        return true;
    }
};

int main() {
    //string sentence = "thequickbrownfoxjumpsoverthelazydog";
    string sentence = "leetcode";

    Solution sol;
    bool ans = sol.checkIfPangram(sentence);

    cout << ans;

    return 0;
}