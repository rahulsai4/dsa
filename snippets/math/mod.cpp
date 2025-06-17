const int mod = 1e9 + 7;
const int N = 1000000;

// a power b
long long mod_pow(long long a, long long b) {
    a %= mod;
    long long res = 1 % mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

// fermat's little theorem
int mod_a_by_b(long long a, long long b){
    a = a % mod;
    int inv_b = mod_pow(b, mod - 2); 
    return (a * inv_b % mod);
}

// ncr
long long fact[N], inv_fact[N];
void precompute(){
    fact[0] = 1;
    
    int i;
    for(i = 1; i < N; i++){
        fact[i] = (i * fact[i - 1]) % mod;
    }
    i--;
    inv_fact[i] = mod_pow(fact[i], mod - 2);
    for(i--; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

int ncr(int n, int r){
    if(r > n || n < 0 || r < 0) return 0;
    return ((fact[n] * inv_fact[r] % mod) * inv_fact[n - r]) % mod;
}