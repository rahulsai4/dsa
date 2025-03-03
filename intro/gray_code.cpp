#include <bits/stdc++.h>
using namespace std;

vector<string> generateGrayCode(int n);
/* 
    intuition => reflection for each i with 1 added before msb
      0
      1
    ---
     11
     10
    ---
    110
    111
    101
    100
*/

int main(){
    int n;
    cin >> n;
    vector<string> res = generateGrayCode(n);
    for(string s : res){
        cout << s << endl;
    }
}

vector<string> generateGrayCode(int n){
    if(n == 1) return {"0", "1"};

    vector<string> prev = generateGrayCode(n - 1);

    for(int i = prev.size() - 1; i >= 0; i--){
        string curr = prev[i];
        prev[i] = "0" + prev[i];

        prev.push_back("1" + curr);
    }

    return prev;
}
