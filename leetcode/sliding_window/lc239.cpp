#include <bits/stdc++.h>
using namespace std;

// using deque
class Solution1 {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> res;
            deque<int> dq;
            for(int start = 0, end = 0; end < n; end++){
                // clear out of bounds elements
                while(!dq.empty() && dq.front() < start) 
                    dq.pop_front();
                
                // monotonic decreasing deque
                while(!dq.empty() && nums[dq.back()] < nums[end])
                    dq.pop_back();
                dq.push_back(end);
                
                // window reached
                if(end - start + 1 == k){
                    res.push_back(nums[dq.front()]);
                    start++;
                }
            }
    
            return res;
        }
};

// using multiset => very slow
class Solution2 {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> res;
            multiset<int> ms;
            for(int start = 0, end = 0; end < n; end++){
                ms.insert(nums[end]);
    
                if(end - start + 1 == k){
                    res.push_back(*ms.rbegin());
                    ms.erase(ms.find(nums[start]));
                    start++;
                }
            }
    
            return res;
        }
};