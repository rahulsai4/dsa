#include <bits/stdc++.h>
using namespace std;

void permutations(string &s, int start, set<string> &res);

int main(){
    string s;
    cin >> s;
    set<string> res;

    permutations(s, 0, res);
    cout << res.size() << endl;
    for(string s : res){
        cout << s << endl;
    }
}

void permutations(string &s, int start, set<string> &res){
    if(start == (int) s.size() - 1){
        res.insert(s);
        return;
    }

    for(int p = start; p < (int) s.size(); p++){
        swap(s[start], s[p]);
        permutations(s, start + 1, res);
        swap(s[start], s[p]);
    }
}