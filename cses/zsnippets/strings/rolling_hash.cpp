#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

vector<long long> compute_hash_prefix(string &s, vector<long long> &powers){
    vector<long long> res(s.length());
    res[0] = (s[0] - 'a') * powers[0];

    for(int i = 1; i < s.length(); i++){
        res[i] = (res[i - 1] + ((s[i] - 'a') * powers[i]) % MOD) % MOD;
    }
    return res;
}

vector<long long> get_powers(int x){
    vector<long long> powers(x);
    powers[0] = 1;

    for(int i = 1; i < x; i++){
        powers[i] = (powers[i - 1] * 31) % MOD;
    }

    return powers;
}

int main() {
    int t, queries, p, q, r, s;
    string a, b;
    cin >> t;
    while(t-- > 0){
        cin >> a;
        cin >> b;
        vector<long long> powers = get_powers(max(a.length(), b.length()));

        vector<long long> hash_pref_a = compute_hash_prefix(a, powers);
        vector<long long> hash_pref_b = compute_hash_prefix(b, powers);

        cin >> queries;
        while(queries-- > 0){
            cin >> p >> q >> r >> s;

            long long val1 = p == 0 ? hash_pref_a[q] : (hash_pref_a[q] - hash_pref_a[p - 1] + MOD) % MOD;
            long long val2 = r == 0 ? hash_pref_b[s] : (hash_pref_b[s] - hash_pref_b[r - 1] + MOD) % MOD;

            if(p < r){
                val1 = (val1 * powers[r - p]) % MOD;
            }
            else if(p > r){
                val2 = (val2 * powers[p - r]) % MOD;
            }

            cout << (val1 == val2 ? "Yes" : "No") << endl;
        }
    }
}



