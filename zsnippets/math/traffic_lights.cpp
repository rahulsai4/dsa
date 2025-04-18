#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, num;
    cin >> n >> k;

    // distances
    multiset<int> lens;
    lens.insert(n);
    // ub to lb
    map<int, int> pos;
    pos[n] = 0;

    for(int i = 0; i < k; i++){
        cin >> num;

        auto it = pos.upper_bound(num);

        int d3 = it->first;
        int d2 = num;
        int d1 = it->second;

        pos[d3] = d2;
        pos[d2] = d1;

        lens.erase(lens.find(d3 - d1));
        lens.insert(d3 - d2);
        lens.insert(d2 - d1);

        cout << *lens.rbegin() << " ";
    }
    cout << endl;
}