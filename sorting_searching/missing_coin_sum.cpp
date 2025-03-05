#include<bits/stdc++.h>
using namespace std;

#define lli long long

lli missing_coin_sum(vector<lli> &nums);

int main(){
    lli n;
    cin >> n;

    vector<lli> nums(n);
    for(lli i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    cout << missing_coin_sum(nums) << endl;
}

lli missing_coin_sum(vector<lli> &nums){
    lli missing_sum = 1;
    for(lli num : nums){
        if(num > missing_sum){
            return missing_sum;
        }

        missing_sum += num;
    }
    return missing_sum;
}