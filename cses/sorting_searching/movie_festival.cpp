#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; i++){
        pair<int, int>* p = &pairs[i];
        cin >> p->first;
        cin >> p->second;
    }
    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.second < p2.second;
    });
 
    int end_time = 0;
    int movies = 0;
    for(pair<int, int> p : pairs){
        if(p.first < end_time) continue;
        else{
            movies++;
            end_time = p.second;
        }
    }
    
    cout << movies << endl;
}