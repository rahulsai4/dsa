#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    size_t n = s.size();

    vector<int> map(26, 0);
    for(size_t i = 0; i < n; i++){
        map[s[i] - 'A']++;
    }

    char first_odd = ' ';
    string res(n, ' ');
    int rdx = 0;

    for(int i = 0; i < 26; i++){
        int count = map[i];
        if(count % 2 != 0){
            if(first_odd != ' '){
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            first_odd = i + 'A';
            count--;
        }
        count /= 2;
        for(int j = 0; j < count; j++){
            res[rdx] = res[n - rdx - 1] = (i + 'A');
            rdx++;
        }
    }

    if(first_odd != ' ') res[rdx] = first_odd;

    cout << res << endl;
    return 0;
}