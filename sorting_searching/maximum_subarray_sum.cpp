// kadane
#include <bits/stdc++.h>
using namespace std;

#define lli long long
 
int main(){
    int n;
    cin >> n;

    vector<lli> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    lli maxSum = nums[0];
    lli currSum = nums[0];
    for(int i = 1; i < n; i++){
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(currSum, maxSum);
    }

    cout << maxSum << endl;
    return 0;
}