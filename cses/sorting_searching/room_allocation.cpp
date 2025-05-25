#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define endl "\n"
int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s, e;
    cin >> n;
    vector<vector<int>> cust(n, vector<int>(3, 0));
    for(int i = 0; i < n; i++){
        cin >> cust[i][0] >> cust[i][1];
        cust[i][2] = i;
    }

    sort(cust.begin(), cust.end(), [](vector<int> &p1, vector<int> &p2){
        if(p1[0] == p2[0]){
            return p1[1] < p2[1];
        }
        return p1[0] < p2[0];
    });

    vector<int> res(n);
    unordered_multiset<int> endTimes;

    int curr = 0;
    int resCount = 0;
    for(int i = 0; i < n; i++){
        s = cust[i][0];
        e = cust[i][1];
        
        curr++;
        
        endTimes.insert(e);
        res[cust[i][2]] = curr;
        resCount = max(resCount, curr);
        if(endTimes.count(s)){
            curr--;
            endTimes.erase(s);
        }
    }

    cout << resCount << endl;
    for(int r : res){
        cout << r << " ";
    }
    cout << endl;
}
