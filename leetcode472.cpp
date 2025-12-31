#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//Method-1
class Solution {
public:

    unordered_map<string, bool> mp;

    bool isConcatenated(string word, unordered_set<string> &st){
        
        if(mp.find(word) != mp.end()){
            return mp[word];
        }

        int l = word.length();

        for(int i = 0; i<l; i++){
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);

            if((st.find(prefix) != st.end() && isConcatenated(suffix,st)) ||
            (st.find(prefix) != st.end() && st.find(suffix) != st.end())){
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int  n = words.size();
        mp.clear();

        //storing all the words into set to excess easily
        unordered_set<string> st(begin(words), end(words));

        vector<string> result;

        //check all the word if they are concatenated, if they are then push(add) them into result.
        for(int i = 0; i<n; i++){
            string word = words[i];

            if(isConcatenated(word, st)){
                result.push_back(word);
            }
        }
        return result;
    }
}; 

int main() {
    //vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};

    //vector<string> words = {"cat","dog","catdog"};
    vector<string> words = {"cat","do","g","catdog"};

    Solution sol;
    vector<string> ans = sol.findAllConcatenatedWordsInADict(words);

    cout << "Output : {";
    for(int i = 0; i<ans.size(); i++){
        cout << "\""<< ans[i] << "\"";
        if(i<ans.size()-1){
            cout << ","<< " ";
        }
    }
    cout << "}";

    return 0;
}