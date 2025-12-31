#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(begin(people), end(people));
        int i = 0;
        int j = n-1;
        int result = 0;

        while(i<=j){
            if(people[i]+people[j] <= limit){
                result++;
                i++;
                j--;
            } else{
                result++;
                j--;
            }
        }
        return result;
    }
};
int main() {
    vector<int> people = {3,2,2,1};
    int limit = 3;

    Solution sol;
    int ans = sol.numRescueBoats(people, limit);

    cout << "Output : " << ans << endl;

    return 0;
}