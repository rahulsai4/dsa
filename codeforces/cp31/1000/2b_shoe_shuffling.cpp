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
    int t = 1, n;
    cin >> t;
    while (t--) {
        cin >> n; 
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        // any number appears only once => return -1;
        // shift the numbers appearing > 1
        vector<int> res(n);
        int i = 0, j = 0;
        while(j < n){
            j = i + 1;
            while(j < n && nums[j] == nums[i]){
                res[j] = j;
                j++;
            }
            
            if(j - i == 1){
                res = {-1};
                break;
            }

            res[i] = j;
            i = j;
        }
        for(int r : res) cout << r << " ";
        cout << nl;
    }
}