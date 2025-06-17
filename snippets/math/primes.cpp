#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; 1LL * i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

// seive of primes => almost linear
void primes(int n){
    // initially all are primes
    vector<int> prime(n + 1, 1);
    prime[1] = 0;
    for(int i = 2; i <= n; i++){
        if(!prime[i]) continue;
        // start from i * i instead of 2i, 3i, 4i, ... no need already marked
        for(int j = i * i; j <= n; j += i){
            prime[j] = 0;
        }
    }
}
