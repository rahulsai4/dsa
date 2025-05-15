#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        using lli = long long;
        int nthUglyNumber(int n) {
            vector<int> dp(n, 0);
            dp[0] = 1;
            // pts for multiplying
            int i2 = 0, i3 = 0, i5 = 0;
            for(int i = 1; i < n; i++){
                lli next2 = 2 * dp[i2];
                lli next3 = 3 * dp[i3];
                lli next5 = 5 * dp[i5];
    
                lli next = min(next2, min(next3, next5));
                dp[i] = next;
    
                if(next2 == next) i2++;
                if(next3 == next) i3++;
                if(next5 == next) i5++;
            }
    
            return dp[n - 1];
        }
};
    
    /*  USING PRIORITY QUEUE
        int nthUglyNumber(int n) {
            set<long long> pq;
            pq.insert(1);
            long long curr;
            for(int i = 0; i < n; i++){
                curr = *pq.begin();
                pq.erase(pq.begin());
                pq.insert(curr * 2);
                pq.insert(curr * 3);
                pq.insert(curr * 5);
            }
    
            return curr;
        }
    */