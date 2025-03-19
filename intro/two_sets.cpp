#include<bits/stdc++.h>
 
using namespace std;
 
int MOD = (int) 1e9 + 7;
 
vector<vector<int>> solve(long long n);
 
int main(){
    int n;
    cin >> n;
 
 
    vector<vector<int>> res = solve(n);
    if(res.size() == 0){
        cout << "NO" << endl;
        return 0;
    }
 
    sort(res[0].begin(), res[0].end());
    sort(res[1].begin(), res[1].end());
 
    cout << "YES" << endl;
    cout << res[0].size() << endl;
    for(int i : res[0]) cout << i << " ";
    cout << endl;
    cout << res[1].size() << endl;
    for(int i : res[1]) cout << i << " ";
    cout << endl;
    
}
 
vector<vector<int>> solve(long long n){
    vector<vector<int>> res;
 
    long long o = n % 2 == 0 ? n : n + 1;
    o = o / 2;
    if(o % 2 != 0) return res;
    if(n == 3) return {{1, 2}, {3}};
 
    vector<int> left;
    vector<int> right;
 
    if(n % 2 == 0){
        for(int i = 1; i <= n / 2; i++){
            if(i % 2 == 0){
                left.push_back(i);
                left.push_back(n - i + 1);
            }
            else{
                right.push_back(i);
                right.push_back(n - i + 1);
            }
        }
 
        
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    else{
        int mid = n / 2 + 1;
        vector<vector<int>> subRes = solve(mid - 1);
        if(subRes.size() == 0) return res;
 
        int i = mid;
        int j = n;
        while(i < j){
            if(i % 2 == 0){
                subRes[0].push_back(i++);
                subRes[0].push_back(j--);
            }
            else{
                subRes[1].push_back(i++);
                subRes[1].push_back(j--);
            }
 
        }
        return subRes;
    }
}