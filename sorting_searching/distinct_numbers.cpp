#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int res = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 || nums[i] != nums[i - 1]) 
            res++;
    }

    cout << res << endl;
    return 0;
}
