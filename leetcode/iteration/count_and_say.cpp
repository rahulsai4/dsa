#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string curr = "1";
        for(int i = 2; i <= n; i++){
            curr = rle(prev);
            prev = curr;
        }

        return curr;
    }

    string rle(string s){
        int i = 0;
        int n = s.length();

        ostringstream oss;

        while(i < n){
            int j = i + 1;
            while(j < n && s[j] == s[i]){
                j++;
            }
            oss << (j - i) << s[i];
            i = j;
        }

        return oss.str();
    }
};