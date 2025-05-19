#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

using lli = long long;
constexpr char nl = '\n';

template <typename T>
void printVec(const vector<T>& vec) {
    for (const auto& elem : vec)
        cout << elem << ' ';
    cout << '\n';
}

int main() {
    int t, n;
    cin >> t;
    while(t-- > 0){
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        bool res = true;
        int prev = nums[0];
        int lossCount = nums[0] == 0 ? 1 : 0;
        for(int i = 1; i < n; i++){
            if(prev == 0 && nums[i] != 1){
                res = false;
                break;
            }
            prev = nums[i];
            if(nums[i] == 0) lossCount++;
        }
        if(lossCount == 0) res = false;
        if(!res) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}