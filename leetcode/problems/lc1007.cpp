#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        bool foundSame = false;
        int foundSameValue = -1;
        int foundSameCount = 0;

        map<int, int> tmap;
        map<int, int> bmap;
        for(int i = 0; i < n; i++){
            if(tops[i] == bottoms[i]){
                if(foundSame && foundSameValue != tops[i]) return -1;
                foundSame = true;
                foundSameValue = tops[i];
                foundSameCount++;
            }
            else{
                tmap[tops[i]]++;
                bmap[bottoms[i]]++;
            }
        }

        int res = INT_MAX;

        if(foundSame){
            int t = tmap.count(foundSameValue) ? tmap[foundSameValue] : 0;
            int b = bmap.count(foundSameValue) ? bmap[foundSameValue] : 0;
            if(t + b >= (n - foundSameCount)){
                res = min(t, b);
            }
            else{
                return -1;
            }
        }
        else{
            for(const auto &[curr, tcount] : tmap){
                if(bmap.count(curr)){
                    int bcount = bmap[curr];
                    if(tcount + bcount >= n){
                        res = min(res, min(tcount, bcount));
                    } 
                }
            }
            for(const auto &[curr, bcount] : bmap){
                if(tmap.count(curr)){
                    int tcount = tmap[curr];
                    if(tcount + bcount >= n){
                        res = min(res, min(tcount, bcount));
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};