#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define endl "\n"
int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
}