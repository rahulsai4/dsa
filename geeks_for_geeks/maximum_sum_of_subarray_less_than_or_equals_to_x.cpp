#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      long long findMaxSubarraySum(vector<int>& arr, long long x) {
          set<long long> prefSet;
          prefSet.insert(0);
          
          long long prefSum = 0;
          long long bestRes = 0;
          for(int i = 0; i < arr.size(); i++){
              prefSum += arr[i];
              
              auto it = prefSet.lower_bound(prefSum - x);
              if(it != prefSet.end()){
                  bestRes = max(bestRes, prefSum - *it);
              }
              
              prefSet.insert(prefSum);
          }
          
          return bestRes;
      }
};
  