#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> lengths(n), pref(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> lengths[i];
        sum += lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    for(int i = 0; i < n; i++){
        pref[i] = lengths[i] + (i == 0 ? 0 : pref[i - 1]);
    }


    long long res = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        long long c1 = ((i + 1) * lengths[i]) - pref[i]; 
        long long c2 = (sum - pref[i]) - ((n - i - 1) * lengths[i]);

        res = min(res, c1 + c2);
    }

    cout << res << endl;
}