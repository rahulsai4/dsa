#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int main()
{
    fast_io;
    int t = 1, n, m, k, l;
    string s;
    while (t--)
    {
        cin >> n;
        int arr[5] = {};
        for(int i = 0; i < n; i++){
            cin >> m;
            arr[m]++;
        }
        
        // 4
        int res = arr[4];
        // 3
        res += arr[3];
        arr[1] -= arr[3];
        
        // 2
        res += (arr[2] / 2);
        arr[2] %= 2;
        if(arr[2] == 1){
            res++;
            arr[1] -= 2;
        }
        // 1
        arr[1] = arr[1] < 0 ? 0 : arr[1];
        res += ceil(arr[1] / 4.0);

        cout << res << endl;

    }
}