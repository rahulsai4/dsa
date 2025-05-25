#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            // sort envelopes by ascending in wd, descending in ht
            sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
                if(a[0] == b[0]) return a[1] > b[1];
                else return a[0] < b[0];
            });

            vector<int> temp;
            for(int i = 0; i < envelopes.size(); i++){
                int curr = envelopes[i][1];
                auto it = lower_bound(temp.begin(), temp.end(), curr);
                if(it == temp.end()) temp.push_back(curr);
                else *it = curr;
            }

            return temp.size();
        }
};