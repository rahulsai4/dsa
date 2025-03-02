#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int res = 0;
    for(int i = 5; i <= n; i *= 5){
        res += (n / i);
    }

    cout << res << endl;
}

// count 5, 25, 125, ....