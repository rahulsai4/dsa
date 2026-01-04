#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& pref, int idx, int cnt){
    int lo = 0, hi = idx;
    int res = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        
        int currCnt = pref[idx] - pref[mid];

        if(currCnt >= cnt){
            lo = mid + 1;
        }
        else{
            res = mid;
            hi = mid - 1;
        }
    }
    return res;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	int acnt = 0, bcnt = 0;
    vector<int> apref(n + 1, 0), bpref(n + 1, 0);

    for(int i = 1; i <= n; i++){
        s[i - 1]  == 'a' ? acnt++ : bcnt++;
        apref[i] = acnt;
        bpref[i] = bcnt;

        int l = bs(bpref, i, b);

        cout << i << " " << l << endl;
    }
}