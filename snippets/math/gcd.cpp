#include <bits/stdc++.h>
using namespace std;

// gcd(a, b) = gcd(a, b - a)
// gcd(a, b) = gcd(a, b % a)
// gcd => log(max(a, b))
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
// use __gcd(a, b) built in function