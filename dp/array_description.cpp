#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int i, int val);
long long solve(vector<int> &arr, int i, vector<int> &dp);

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<int> dp(n + 1, -1);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long res = solve(arr, 0, dp);
    cout << res << "\n";
}

long long solve(vector<int> &arr, int i, vector<int> &dp){
    if(i == arr.size()){
        return 1;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    if(arr[i] == 0){
        long long res = 0;
        
        if(i > 0){
            int left = arr[i - 1];
            for(int j = -1; j <= 1; j++){
                if(isValid(arr, j, left + j)){
                    arr[i] = left + j;
                    res += solve(arr, j + 1, dp);
                }
            }
            arr[i] = 0;
        }
        
        return dp[i] = res;
    }
    else{
        return dp[i] = solve(arr, i + 1, dp);
    }
}

bool isValid(vector<int> &arr, int i, int val){
    if(i > 0 ){
        if(abs(val - arr[i - 1]) > 1) return false;
    }
    if(i < arr.size() - 1 && (arr[i + 1] != 0)){
        if(abs(val - arr[i + 1]) > 1) return false;
    }
    return true;
}