#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++) {
        long long totalWays = (k * k * (k * k - 1)) / 2;
        long long attackingWays = 4 * (k - 1) * (k - 2);
        cout << (totalWays - attackingWays) << endl;
    }
}

// finding the number of [2, 3] and [3, 2] blocks
// (k - 1) -> select row / col => size(2)
// *
// (k - 2) -> select row / col => size(3)
// each block will contain 2 knight placements