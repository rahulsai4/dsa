#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
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
	while (t--) {
		cin >> n >> k;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
        
        bool res = false;
        for(int num: nums) 
            if(num == k)
                res = true;
        
        if(res) yes;
        else no;
	}
}
// for(int i = 0; i < n; i++){
//     map<int, int> freq;
//     int max_freq = 0;

//     for(int j = i; j < n; j++){
//         int num = nums[j];

//         freq[num]++;
//         if(num != k){
//             max_freq = max(max_freq, freq[num]);
//         }

//         if(j - i + 1 > 1 && freq[k] > max_freq){
//             res = true;
//             break;
//         }

//         cout << i << " " << j << " " << freq[num] << endl;
//     }
//     if(res) break;
// }