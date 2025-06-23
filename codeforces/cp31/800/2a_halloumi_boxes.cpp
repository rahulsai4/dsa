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

int main() {
    fast_io;
    int t = 1, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int nums[n];
        for(int i = 0; i < n; i++) cin >> nums[i];

        if(is_sorted(nums, nums + n) || k >= 2) yes;
        else no;
    }
}