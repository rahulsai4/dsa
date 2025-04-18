#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n;
    while(n-- > 0){
        cin >> r >> c;
        long long idx = max(r, c);

        long long start = (idx - 1) * (idx - 1) + 1;
        long long end = start + ((idx - 1) * 2);
        long long res;

        if(idx % 2 == 0){
            // even
            res = (c == idx) ? start + (r - 1) : end - (c - 1);
        }
        else{
            // odd
            res = (r == idx) ? start + (c - 1) : end - (r - 1);
        }
        

        cout << res << endl;
    }
}