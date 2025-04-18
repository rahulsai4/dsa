#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, num;
    cin >> n;

    multiset<int> towers;

    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> num;
        auto ub = towers.upper_bound(num);
        if(towers.empty() || (ub == towers.end())){
            res++;
            towers.insert(num);
        }   
        else{
            //auto it = towers.find(*ub);
            towers.erase(ub);
            towers.insert(num);
        }
    }

    cout << res << endl;
}