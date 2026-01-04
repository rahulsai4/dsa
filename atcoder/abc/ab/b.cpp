#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(string &x: v) cin >> x;

    unordered_set<string> st;

    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            string curr = "";
            for(int k = i; k < i + m; k++){
                for(int l = j; l < j + m; l++){
                    curr += v[k][l];
                }
                curr += ",";
            }
            st.insert(curr);
        }
    }

    cout << st.size() << endl;
}