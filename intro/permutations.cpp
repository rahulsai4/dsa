#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n > 1 && n < 4){
        cout << "NO SOLUTION" << endl;
    }
    else{
        int c = (n % 2 == 0) ? n / 2 : (n + 1) / 2;

        int p1 = 1;
        int p2 = c + 1;

        if(n % 2 == 0) swap(p1, p2);

        for(int i = 1; i <= n; i++){
            int curr;
            if(i % 2 == 0) curr = p2++;
            else curr = p1++;
            cout << curr << " ";
        }
        cout << endl;
    }
}