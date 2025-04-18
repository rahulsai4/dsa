#include<bits/stdc++.h>
using namespace std;
 
#define lli long long
 
int sliding_window(vector<int> &nums, int n);
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
 
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout << sliding_window(nums, n) << endl;
}
 
int sliding_window(vector<int> &nums, int n){
    map<int, int> idx;
    int res = 1;
    for(int start = 0, end = 0; end < n; end++){
        int curr = nums[end];
        if(idx.count(curr) && idx[curr] >= start){
            start = idx[curr] + 1;
        }
 
        idx[curr] = end;
        res = max(res, end - start + 1);
    }
 
    return res;
}