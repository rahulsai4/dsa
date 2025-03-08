#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

vector<int> get_primes(int right);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes = get_primes(1000000);
    for(int prime : primes) cout << prime << " ";
    cout << endl;
    
}

vector<int> get_primes(int right){
    vector<int> primes;

    vector<bool> isPrime(right + 1, true);

    isPrime[0] = isPrime[1] = false;

    int until = sqrt(right);
    for(long long i = 2; i <= until; i++){
        if(isPrime[i]){
            for(long long j = i * i; j <= right; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i <= right; i++){
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}