#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string d) {
        int n = d.length();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            left[i] = l == -1 ? -1 : i - l;
            if(d[i] == 'R') l = i;
            else if(d[i] == 'L') l = -1;

            int j = n - i - 1;
            right[j] = r == -1 ? -1 : r - j;
            if(d[j] == 'L') r = j;
            else if(d[j] == 'R') r = -1;
        }

        string res = d;
        for(int i = 0; i < n; i++){
            if(d[i] == '.'){
                if(left[i] == -1 && right[i] == -1) continue;
                if(left[i] == -1){
                    res[i] = 'L';
                } 
                else if(right[i] == -1){
                    res[i] = 'R';
                }
                else{
                    if(right[i] > left[i]){
                        res[i] = 'R';
                    }
                    else if(right[i] < left[i]){
                        res[i] = 'L';
                    }
                }
            }
        }

        return res;
    }
};