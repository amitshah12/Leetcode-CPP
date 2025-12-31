#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> result;

        unordered_map<string, vector<string>>mp;

        //
        for(int i=0; i<n; i++){
            string temp = strs[i];

            sort(begin(temp), end(temp));

            //Pushing string corresponding vector into map
            mp[temp].push_back(strs[i]);
        }

        //iterating into map and pushing all the answer into map
        for(auto it : mp){
            result.push_back(it.second);
        }
        
        return result;
    }
};

int main() {
    //vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = {"build", "dubli"};

    Solution sol;
    vector<vector<string>> Output = sol.groupAnagrams(strs);

    cout << "Output = [";
    for (int i = 0; i < Output.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < Output[i].size(); ++j)
        {
            cout << Output[i][j];
            if (j < Output[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < Output.size() - 1)
            cout << ",";
    }
    cout << "]\n";

    return 0;
}