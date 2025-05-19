#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            // solved using stack
            // stack stores pairs {startInd ( or can extend ind), ht}
            heights.push_back(0);
            stack<pair<int, int>> s;
    
            int res = 0;
            for(int i = 0; i < heights.size(); i++){
                int currHt = heights[i];
                int currInd = i;
                while(!s.empty() && s.top().first > heights[i]){
                    auto [ht, ind] = s.top();
                    s.pop();
                    // here i is used because i am updating the currIdx after each iteration
                    // i - initial position of the currentHt
                    int wd = (i - ind);
                    res = max(res, ht * wd);
    
                    // now ht of i can be extend to idx because hts[idx] > hts[i]
                    currInd = ind;
                }
                s.push({currHt, currInd});
            }
            return res;
        }
};