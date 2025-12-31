#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*Leetcode-869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 10
Output: false

Constraints:
1 <= n <= 109
*/

class Solution {
public:
//Approach-1:
    // string getSortedStr(int n){
    //     string s = to_string(n);
    //     sort(begin(s), end(s));
    //     return s;
    // }
    // bool reorderedPowerOf2(int n) {
    //     string s = getSortedStr(n);

    //     for(int p=0; p<=29; p++){
    //         if(s == getSortedStr(1 << p)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    //Approach-2
    // unordered_set<string> st;
    // void buildSet(){
    //     //2^p from p=0 to 29
    //     //convert to string
    //     //sort it
    //     //store it in st
    //     for(int p=0; p<=29; p++){
    //         string s = to_string(1 << p);
    //         sort(begin(s), end(s));
    //         st.insert(s);
    //     }
    // }

    // bool reorderedPowerOf2(int n) {
    //     if(st.empty()){
    //         buildSet(); //call only once(static)
    //     }
    //     string s = to_string(n);
    //     sort(begin(s), end(s));

    //     return st.count(s);
    // }


    //Approach-3
    vector<int> getVectorCountFormat(int n){
        vector<int> vec(10, 0);

        while(n){
            vec[n%10]++;
            n = n/10;
        }
        return vec;
    }

    bool reorderedPowerof2(int n){
        vector<int> input = getVectorCountFormat(n);

        for(int p=0; p<=29; p++){
            if(input == getVectorCountFormat(1 << p)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout<<"Enter number: ";
    int n;
    cin>>n;

    Solution sol;
    bool Ans = sol.reorderedPowerof2(n);
    
    cout<<"Ans = "<< Ans;

    return 0;
}