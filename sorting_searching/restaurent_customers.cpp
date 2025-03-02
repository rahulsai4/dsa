#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> events;
    while(n-- > 0){
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());
    
    int currCustomers = 0;
    int maxCustomers = 0;
    for(pair<int, int> p : events){
        currCustomers += p.second;
        maxCustomers = max(maxCustomers, currCustomers);
    }

    cout << maxCustomers << endl;

}

// prefix array
// no need to store the entire array
// just store the events
// sort the events
// process the events
// store the max value
