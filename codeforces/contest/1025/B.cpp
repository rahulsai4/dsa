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

void helper(int n, int m, int r, int c){
    int res = 0;
    while(n != 1 || m != 1){
        res++;
        long long top, bottom, left, right, yArea = 0, xArea = 0;
        if(n > 1){
            top = r - 1;
            bottom = n - r;
            yArea = max(top * m, bottom * m);

        }
        if(m > 1){
            left = c - 1;
            right = m - c;
            xArea = max(left * n, right * n);
        }


        if(yArea < xArea){
            if(left == 0) m = right;
            else if(right == 0) m = left;
            else m = min(left, right);
        }
        else{
            if(top == 0) n = bottom;
            else if(bottom == 0) n = top;
            else n = min(top, bottom);
        }

        // place monster
        r = (n + 1) / 2;
        c = (m + 1) / 2;
    }

    cout << res << nl;
}


int main() {
    int t, n, m, r, c;
    cin >> t;
    while(t-- > 0){
        cin >> n >> m >> r >> c;
        helper(n, m, r, c);
    }
}