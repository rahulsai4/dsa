#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> freq;
        for(int num : answers) freq[num]++;

        int res = 0;

        for(auto &it: freq){
            while(it.second > 0){
                res += it.first + 1;
                it.second -= (it.first + 1);
            }
        }

        return res;
    }
};