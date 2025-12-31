#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*Leetcoe-2007. Find Original Array From Doubled Array
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        //odd length
        if(n % 2 != 0){
            return {};
        }

        sort(begin(changed), end(changed));

        map<int, int> mp;

        //store frequency of each number 
        for(int &num : changed){
            mp[num]++;
        }

        vector<int>result;

        for(int &num : changed){
            int twice = 2 * num;
            
            if(mp[num]==0) continue; //skip

            if(mp.find(twice) == mp.end() || mp[twice]==0){
                return {};
            }

            result.push_back(num);

            mp[num]--;
            mp[twice]--;
        }
        return result;
    }
};

int main() {
    vector<int> changed = {1,3,4,2,6,8};

    Solution sol;
    vector<int> Output = sol.findOriginalArray(changed);

    cout<< "Output : {";
    for(int i = 0; i<Output.size(); i++){
        cout << Output[i];
        if(i < Output.size()-1){
            cout << ",";
        }
    }
    cout << "}";

    return 0;
}