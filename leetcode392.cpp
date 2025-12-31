#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//Method -1
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int m = s.length();
//         int n = t.length();

//         int i = 0;
//         int j = 0;
//         while(i<m && j<n){
//             if(s[i] == t[j]){
//                 i++;
//                 j++;
//             }else{
//                 j++;
//             }
//         }

//         if(i==m){
//             return true;
//         }
//         return false;
//     }
// };

//Method-2
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        map<char, vector<int>>idx;//char->indices
        //insert char of t in map with their indices
        for(int i = 0; i<n; i++){
            idx[t[i]].push_back(i);
        }
        
        int prev = -1;
        //iterate over char of s and check if it is present in t
        for(int i = 0; i<m; i++){
            char ch = s[i];

            
            if(idx.find(ch) == idx.end()){
                return false;
            }
            vector<int> indices = idx[ch];

            auto it = upper_bound(begin(indices), end(indices),prev);

            if(it == indices.end()){
                return false;
            }
            prev = *it;
        }
        return true;
    }
};

int main() {
    string s = "abc";
    string t = "ahbgdc";
    
    // string s = "aabc";
    // string t = "ahabgdc";

    Solution sol;
    bool ans = sol.isSubsequence(s,t);

    cout << "Output : " << ans << endl;

    return 0;
}