#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> prev(n, -1);
    vector<int> len(n, 1);

    int startPtr = 0;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if((len[j] + 1 > len[i]) && (nums[i] % nums[j] == 0)){
                prev[i] = j;
                len[i] = len[j] + 1;
            }
        }
        if(len[i] > len[startPtr]) startPtr = i;
    }

    vector<int> res;
    while(startPtr != -1){
        res.push_back(nums[startPtr]);
        startPtr = prev[startPtr];
    } 
    reverse(res.begin(), res.end());

    return res;
}
