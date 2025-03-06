#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    multiset<int> ms;
    for(int i = 1; i <= n; i++) ms.insert(i);

    auto it = ms.begin();
    while(ms.size() >= 2){
        it++;
        cout << *it << " ";
        ms.erase(it);
        it++;
    }
    cout << *ms.begin() << endl;
}