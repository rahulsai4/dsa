#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

map<int, int> findSub(vector<int> &nums, int n) {
    map<int, int> um;
    int i = 0, j = 0;
    while(j < n) {
        while(j < n && nums[j] == nums[i]) j++;

        int curr = nums[i];
        if(um.find(curr) == um.end()) um[curr] = 1;
        um[curr] = max(um[curr], j - i);
        i = j;
    }
    return um;
}

int main() {
    fast_io;
    int t = 1, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi nums1(n), nums2(n);
        for(int i = 0; i < n; i++) cin >> nums1[i];
        for(int i = 0; i < n; i++) cin >> nums2[i];
        
        map<int, int> um1 = findSub(nums1, n);
        map<int, int> um2 = findSub(nums2, n);
        
        int res = 1;
        for(auto it : um2){
            res = max(res, it.second);
        }
        for(auto it : um1){
            res = max(res, it.second);
            if(um2.find(it.first) != um2.end()){
                res = max(res, it.second + um2[it.first]);
            }
        }

        cout << res << nl;
    }
}