#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int modularNcr(int n, int r){
    if(r < 0 || r > n) return 0;

    lli a = fact(n);
    lli b = (fact(n - r) * fact(r)) % MOD;

    return a * aPowerN(b, MOD - 2) % MOD;
}

lli fact(int n){
    return n;
}

lli aPowerN(int a, int n){
    // use binary exponentiation
    return a;
}