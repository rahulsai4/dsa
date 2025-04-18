#include <bits/stdc++.h>
using namespace std;

void solve(int n, int src, int helper, int dst);
long long a_power_n(int a, int n);

int main(){
    int n;
    cin >> n;

    cout << (a_power_n(2, n) - 1) << endl;
    solve(n, 1, 2, 3);
}

void solve(int n, int src, int helper, int dst){
    if(n == 0) return;

    solve(n - 1, src, dst, helper);
    cout << src << " " << dst << endl;
    solve(n - 1, helper, src, dst);
}

long long a_power_n(int a, int n){
    long long res = 1;
    long long power = a;
    while(n != 0){
        if((n & 1) == 1){
            res = (res * power);
        }
        power = (power * power);
        n >>= 1;
    }
    return res;
}