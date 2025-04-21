#include<bits/stdc++.h>
using namespace std;

// Binary Search --> Math

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long highest = 0;
        long long lowest = 0;
        long long curr = 0;

        for(int diff : differences){
            curr += diff;

            highest = max(curr, highest);
            lowest = min(curr, lowest);
        }

        // a + lowest >= lower => a >= lower - lowest
        // a + highest <= upper => a <= upper - highest
        long long left = lower - lowest;
        long long right = upper - highest;
        return max(0LL, right - left + 1);
      
    }
};


/* method1 binary search slow
class Solution {
    public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int res = 0;
        
        int c = floorOrCeil(differences, lower, upper, false);
        int f = floorOrCeil(differences, lower, upper, true);

        return f == INT_MIN ? 0 : c - f + 1;
    }

    int floorOrCeil(vector<int> &diffs, int lower, int upper, bool isFloor){
        int lo = lower;
        int hi = upper;
        int res = INT_MIN;
        while(lo <= hi){
            long long mid = (hi + lo) / 2;

            pair<bool, bool> breakRes = breaks(diffs, lower, upper, mid);
            bool breaksUpper = breakRes.second;
            bool breaksLower = breakRes.first;

            if(breaksUpper){
                hi = mid - 1;
            }
            else if(breaksLower){
                lo = mid + 1;
            }
            else{
                if(isFloor) hi = mid - 1;
                else lo = mid + 1;

                res = mid;
            }
            
        }
        return res;
    }

    // returns {breaksLower, breaksUpper}
    pair<bool, bool> breaks(vector<int> &diffs, int lower, int upper, long long start){
        for(int &num : diffs){
            start += num;
            if(start > upper) return {false, true};
            if(start < lower) return {true, false};
        }
        return {false, false};
    }
};
*/