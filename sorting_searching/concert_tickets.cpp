#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ticket;
    cin >> n >> m;
    map<int, int> tickets;
    vector<int> customer(m);
    for(int i = 0; i < n; i++){
        cin >> ticket;
        tickets[ticket]++;
    }
    for(int i = 0; i < m; i++) cin >> customer[i];

    int i = 0;
    for(int j = 0; j < m; j++){
        auto it = tickets.upper_bound(customer[j]);

        if(it == tickets.begin()){
            cout << "-1" << endl;
        }
        else{
            it--;
            cout << it->first << endl;
            it->second--;
            if(it->second == 0) tickets.erase(it);
        }
    }

}