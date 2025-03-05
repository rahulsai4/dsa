#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    cin >> n;

    unordered_map<int, int> idx;
    for(int i = 1; i <= n; i++){
        cin >> num;
        idx[num] = i;
    }

    int res = 0;
    int i = 1;
    while(i <= n){
        // particular set
        int j = i;
        int start = idx[j++];
        while(idx[j] > start){
            start = idx[j];
            j++;
        }
        i = j;
        res++;
    }

    cout << res << endl;
}