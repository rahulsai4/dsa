#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort and 2ptr

int main(){
    int n, m, k;
    cin >> n; cin >> m; cin >> k;
    vector<int> need(n);
    vector<int> avail(m);
    for(int i = 0; i < n; i++) cin >> need[i];
    for(int j = 0; j < m; j++) cin >> avail[j];
    sort(need.begin(), need.end());
    sort(avail.begin(), avail.end());

    int res = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        int currentNeed = need[i];
        int currentAvail = avail[j];

        int lb = currentNeed - k;
        int ub = currentNeed + k;

        if(currentAvail >= lb && currentAvail <= ub){
            res++;
            i++;
            j++;
        }
        else if(currentAvail < lb){
            j++;
        }
        else if(currentAvail > ub){
            i++;
        }
    } 

    cout << res << endl;
    return 0;
}