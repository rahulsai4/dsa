#include <bits/stdc++.h>
using namespace std;

// solution 2 using pure greedy
class Solution2 {
    public:
        int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
            int y1 = 0, y2 = 0, y3 = 0;
            int x1 = -1, x2 = -1, x3 = -1;
    
            for(int i = 0; i < x.size(); i++){
                if(x[i] == x1){
                    if(y[i] > y1) y1 = y[i];
                }
                else if(x[i] == x2){
                    if(y[i] > y2) y2 = y[i];
                }
                else if(x[i] == x3){
                    if(y[i] > y3) y3 = y[i];
                }
                else{
                    int mini = min(y1, min(y2, y3));
                    if(y[i] > mini){
                        if(y1 == mini){
                            y1 = y[i];
                            x1 = x[i];
                        }
                        else if(y2 == mini){
                            y2 = y[i];
                            x2 = x[i];
                        }
                        else if(y3 == mini){
                            y3 = y[i];
                            x3 = x[i];
                        }
                    }
                }
            }
    
            if(y1 == 0 || y2 == 0 || y3 == 0) return -1;
            return y1 + y2 + y3;
        }
};

// solution 1 using priority queue sufficient but a better greedy way exists
class Solution1 {
    public:
        int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
            int n = x.size();
            auto cmp = [&](int a, int b){
                return y[b] > y[a];
            };
            priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
            for(int i = 0; i < n; i++) pq.push(i);
    
    
            int res = 0;
            set<int> seen;
            while(!pq.empty() && seen.size() < 3){
                int i = pq.top();
                pq.pop();
    
                if(!seen.count(x[i])){
                    res += y[i];
                    seen.insert(x[i]);
                } 
            }
    
            if(seen.size() < 3) return -1;
            else return res;
        }
};