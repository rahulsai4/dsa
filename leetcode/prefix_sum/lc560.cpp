#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& v, int k) {
            map<int, int> m;
            m[0]++;
    
            int sum = 0;
            int count = 0;
            for(int num : v){
                sum += num;
                if(m.count(sum - k)){
                    count += m[sum - k];
                }
                m[sum]++;
            }
    
            return count;
        }
};