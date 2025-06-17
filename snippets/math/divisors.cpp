#include <bits/stdc++.h>
using namespace std;

// count all divisors from 1 to n in < (n * log n) time
// iterate on multiples
vector<int> divisors1ToN(int n){
    vector<int> div(n + 1);
    for(int i = 1; i < n; i++){
        for(int j = i; j <= n; j += i){
            div[j]++;
        }
    }
    return div;
}

// number of divisors of a number in sqrt n time
int divisors(int n){
    int cnt = 0;
    for(int i = 1; 1LL * i * i <= n; i++){
        if(n % i == 0){
            cnt++;
            if(i != n / i)
                cnt++;
        }
    }
    return cnt;
}