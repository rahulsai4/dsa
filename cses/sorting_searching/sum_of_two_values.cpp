#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, t;
    cin >> n >> t;
    
    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
 
    int i = 0, j = (int) nums.size() - 1;
    while(i < j){
        int curr = nums[i].first + nums[j].first;
        if(curr > t){
            j--;
        }
        else if(curr < t){
            i++;
        }
        else{
            cout << nums[i].second << " " << nums[j].second << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}