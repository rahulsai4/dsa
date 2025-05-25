#include <bits/stdc++.h>
using namespace std;

// solution 1 using multiset O(N * log N)
class Solution1 {
    public:
        int numberOfWeakCharacters(vector<vector<int>>& properties) {
            map<int, vector<int>> m;
            for(vector<int> &stats : properties){
                m[stats[0]].push_back(stats[1]);
            }
    
            int res = 0;
            multiset<int> ms;
            for(auto &[d, attacks] : m){
                for(int a : attacks){
                    auto it = ms.lower_bound(a);
                    res += distance(ms.begin(), it);
                    ms.erase(ms.begin(), it);
                }
                for(int a : attacks){
                    ms.insert(a);
                }
            }
    
            return res;
        }
};

// solution using stack O(2 * N)
class Solution2 {
    public:
        int numberOfWeakCharacters(vector<vector<int>>& props) {
            sort(props.begin(), props.end(), [](const vector<int> &a, const vector<int> &b){
                if(a[0] == b[0]) return a[1] > b[1];
                else return a[0] < b[0];
            });
    
            int res = 0;
            // monotonic decreasing stack contains indices
            stack<int> s;
            for(int i = 0; i < props.size(); i++){
                while(!s.empty() && props[s.top()][1] < props[i][1] && props[s.top()][0] != props[i][0]){
                    s.pop();
                    res++;
                }
                s.push(i);
            }
    
            return res;
        }
};

// solution using max O(N)
class Solution3 {
    public:
        int numberOfWeakCharacters(vector<vector<int>>& props) {
            sort(props.begin(), props.end(), [](const vector<int> &a, const vector<int> &b){
                if(a[0] == b[0]) return a[1] > b[1];
                else return a[0] < b[0];
            });
    
            
            int res = 0;
            int maxDefence = 0;
            // iterating from back
            for(int i = props.size() - 1; i >= 0; i--){
                // if currentDefence < maxDefence then definitely both are from different groups 
                // they can't be same group because defence's are sorted in descending order
                // if we traverse from the end the defence's from the same group can never clash with each other
                if(props[i][1] < maxDefence){
                    res++;
                }
                maxDefence = max(maxDefence, props[i][1]);
            }
            
            return res;
        }
};