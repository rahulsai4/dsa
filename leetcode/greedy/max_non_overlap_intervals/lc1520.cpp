#include <bits/stdc++.h>
using namespace std;

// solution 1 using the same logic of non overlapping sub problems
class Solution1 {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            int n = s.length();
            // first and last occurences
            vector<int> l(26, INT_MAX), r(26, INT_MIN);
            for(int i = 0; i < n; i++){
                int c = s[i] - 'a';
                l[c] = min(l[c], i);
                r[c] = max(r[c], i);
            }
    
            // forming intervals
            vector<pair<int, int>> intervals;
            vector<bool> seen(26, false);
            for(int i = 0; i < n; i++){
                int ic = s[i] - 'a';
                if(seen[ic]) continue;
                int icl = l[ic];
                int icr = r[ic];
    
                bool valid = true;
                for(int j = icl; j <= icr; j++){
                    int jc = s[j] - 'a';
                    if(l[jc] < icl){
                        valid = false;
                        break;
                    }
                    icr = max(icr, r[jc]);
                }
    
                if(valid){
                    //cout << icl << " " << icr << endl;
                    intervals.push_back({icl, icr});
                }
                seen[ic] = true;
            }
    
            // no overlap intervals max problem
            sort(intervals.begin(), intervals.end(), [](pair<int, int> &a, pair<int, int> &b){
                if(a.second == b.second) return a.first > b.first;
                else return a.second < b.second;
            });
            vector<string> res;
            int end = -1;
            for(pair<int, int> &p : intervals){
                if(p.first > end){
                    res.push_back(s.substr(p.first, p.second - p.first + 1));
                    end = p.second;
                }
            }
    
            return res;
        }
};
// solution 2 using the better greedy one pass method
class Solution2 {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            int n = s.length();
    
            // first and last occurances
            vector<int> l(26, INT_MAX), r(26, INT_MIN);
            for(int i = 0; i < n; i++){
                int c = s[i] - 'a';
                l[c] = min(l[c], i);
                r[c] = max(r[c], i);
            }
    
            // forming intervals
            int prevRight = -1;
            vector<string> res;
            for(int i = 0; i < n; i++){
                int ic = s[i] - 'a';
                int icl = l[ic];
                // not the first occurance of ic then no point in recalculating as it is already calculated
                if(i > icl) continue;
                int icr = r[ic];
    
                // if the left most occarance of any char in the substring icl to icr is before icl no need to recalculate
                // so not valid
                bool valid = true;
                for(int j = icl; j <= icr; j++){
                    int jc = s[j] - 'a';
                    if(l[jc] < icl){
                        valid = false;
                        break;
                    }
                    icr = max(icr, r[jc]);
                }
    
                // valid substring from icl to icr
                if(valid){
                    // if overlap but end before the prev inserted substring
                    if(icr < prevRight) res.pop_back();
                    // now no overlap 
                    res.push_back(s.substr(icl, icr - icl + 1));
                    prevRight = icr;
                }
            }
            return res;
        }
    };