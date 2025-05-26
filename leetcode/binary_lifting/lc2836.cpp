#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long getMaxFunctionValue(vector<int>& receiver, long long k) {
            int n = receiver.size();
            long long maxDepth = 0;
            while ((1LL << maxDepth) <= k)
                maxDepth++;
            vector<vector<int>>kthParent(n, vector<int>(maxDepth, -1));
            vector<vector<long long>>kthSum(n, vector<long long>(maxDepth, 0));
    
            for (int j = 0; j < n; j++) {
                kthParent[j][0] = receiver[j];
                kthSum[j][0] = receiver[j];
            }
    
            for (int i = 1; i < maxDepth; i++) {
                for (int j = 0; j < n; j++) {
                    int curr = kthParent[j][i - 1];
                    kthParent[j][i] = kthParent[curr][i - 1];
                    kthSum[j][i] += kthSum[curr][i - 1];
                    kthSum[j][i] += kthSum[j][i - 1];
                }
            }
    
            long long res = 0;
            for(int i = 0; i < n; i++){
                long long temp = k;
                int node = i;
                long long sum = i;
                int jump = 0;
                while(temp > 0){
                    if(temp & 1){
                        sum += kthSum[node][jump];
                        node = kthParent[node][jump];
                    }
                    temp = temp >> 1;
                    jump++;
                }
    
                res = max(res, sum);
            }
    
            return res;
        }
};