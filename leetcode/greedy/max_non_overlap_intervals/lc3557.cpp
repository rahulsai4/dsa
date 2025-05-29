#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubstrings(string word) {
            vector<int> arr(26, -1);
            int res = 0;
            for(int i = 0; i < word.length(); i++){
                int curr = word[i] - 'a';
                if(arr[curr] == -1){
                    arr[curr] = i;
                }
                else if(i - arr[curr] + 1 >= 4){
                    // found the interval
                    res++;
                    // reset the array
                    for(int i = 0; i < 26; i++) arr[i] = -1;
                }
            }
            return res;
        }
    };