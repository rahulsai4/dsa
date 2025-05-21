#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maximumSumRectangle(vector<vector<int>> &mat) {
          // code here
          int n = mat.size();
          int m = mat[0].size();
          
          int res = INT_MIN;
          
          for(int i = 0; i < m; i++){
              vector<int> temp(n, 0);
              for(int j = i; j < m; j++){
                  for(int k = 0; k < n; k++){
                      temp[k] += mat[k][j];
                  }
                  res = max(res, maxSubarray(temp));
              }
          }
          
          return res;
      }
      
      int maxSubarray(vector<int> &arr){
          int maxi = INT_MIN;
          int sum = 0;
          for(int i = 0; i < arr.size(); i++){
              sum += arr[i];
              maxi = max(sum, maxi);
              sum = max(0, sum);
          }
          
          return maxi;
      }
  };
  