#include <bits/stdc++.h>
using namespace std;

int helper(int x, int k){
    for(int i = 0; i < 32; i++){
        int bit = k & 1;
        
        if(bit == 1){
            x = x ^ (1 << i);
        }
        
        k = k >> 1;
        if(k == 0) break;
    }
    
    return x;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t-- > 0){
	    int n, x;
	    cin >> n >> x;
	    
	    vector<int> res(n + 1, -1);
	    for(int i = 1; i <= n; i++){
	        if(i == x) res[i] = i;
	        else if((x | i) > x){
	            res[i] = i;
	        }
	        else{
	            int h = helper(x, i);
	            if(h > n) res[i] = i;
	            else res[i] = h;
	        }
	    }
	    
	    for(int i = 1; i <= n; i++){
	        cout << res[i] << " ";
	    }
	    cout << endl;
	}

}
