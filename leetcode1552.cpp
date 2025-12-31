#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Also known as Aggressive cows problem*/
/*Leetcode 1552 : Magnetic Force Between Two Balls
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
*/

class Solution
{
    bool isPossible(vector<int> &position, int m, int mid)
    {
        int count = 1;
        int lastPos = position[0];

        for(int i=0; i<position.size(); i++){
            if(position[i]-lastPos >= mid){
                count++;
                if(count == m){
                    return true;
                }
                lastPos = position[i];
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());

        int s = 0;
        int maxi = -1;
        for (int i = 0; i < position.size(); i++)
        {
            maxi = max(maxi, position[i]);
        }
        int e = maxi;
        int ans = -1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (isPossible(position, m, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1,2,3,4,7}; 
    int m = 3;

    Solution sol;
    cout << "Required force is: " << sol.maxDistance(arr, m) << endl;

    return 0;
}