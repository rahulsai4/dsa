#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    vector<int> wts(n);
    for(int i = 0; i < n; i++) cin >> wts[i];
    sort(wts.begin(), wts.end());

    // 2ptr
    int i = 0, j = n - 1;
    int gondolas = 0;
    while(i <= j){
        int c1 = wts[i];
        int c2 = wts[j];

        if(c1 + c2 <= x) i++;
        gondolas++;
        j--;

    }

    cout << gondolas << endl;
    return 0;
}
