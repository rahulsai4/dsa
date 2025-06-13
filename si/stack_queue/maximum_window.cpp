#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int mod = (int) 1e9 + 7;
    cin >> t;

    while(t-- > 0){
        int w;
        cin >> n >> w;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        // monotonic decreasing deque
        deque<int> dq;
        vector<int> res;

        for(int start = 0, end = 0; end < n; end++){
            while(!dq.empty() && arr[dq.back()] <= arr[end])
                dq.pop_back();

            dq.push_back(end);

            if(end - start + 1 == w){
                if(dq.front() < start) dq.pop_front();
                res.push_back(dq.front());
                start++;
            }
        }

        int sum = 0;
        for(int r : res) sum += arr[r];
        cout << sum << endl;
    }
}