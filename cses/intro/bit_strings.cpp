#include <bits/stdc++.h>
using namespace std;

#define MOD (1e9 + 7);
int a_power_n(int a, int n);

int main(){
    int n;
    cin >> n;

    // a ^ n
    cout << a_power_n(2, n) << endl;
}

// binary exponentiation -> think of the power in binary form
int a_power_n(int a, int n){
    long long res = 1;
    long long power = a;
    while(n != 0){
        if((n & 1) == 1){
            res = (res * power) % (int) MOD;
        }
        power = (power * power) % (int) MOD;
        n >>= 1;
    }
    return res;
}