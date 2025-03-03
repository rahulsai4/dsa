#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> nums, int i, long long sum, long long &minDiff, long long &total);

int main(){
    int n;
    cin >> n;
    
    long long total = 0;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        total += nums[i];
    }

    long long minDiff = LLONG_MAX;
    solve(nums, 0, 0, minDiff, total);
    cout << minDiff << endl;
    
}

void solve(vector<long long> nums, int i, long long sum, long long &minDiff, long long &total){
    if(i == (int) nums.size()){
        minDiff = min(minDiff, abs(total - sum - sum));
        return;
    }

    solve(nums, i + 1, sum, minDiff, total);
    solve(nums, i + 1, sum + nums[i], minDiff, total);
}