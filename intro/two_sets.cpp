#include <bits/stdc++.h>
using namespace std;

bool helper(int n, long target, vector<int> &temp, vector<int> &res);

// brute force
int main(){
    int n;
    cin >> n;
    long sum = (n * (n + 1)) / 2;

    vector<int> list1;
    vector<int> temp;
    if(sum % 2 != 0){
        cout << "NO" << endl;
    }
    else{
        helper(n, sum / 2, temp, list1);
        reverse(list1.begin(), list1.end());
        
        vector<int> list2;
        int i = 0;
        for(int j = 1; j <= n; j++){
            if(list1[i] == j) i++;
            else list2.push_back(j);
        }

        reverse(list2.begin(), list2.end());

        cout << "YES" << endl;
        cout << list1.size() << endl;
        for(int num : list1) cout << num << " ";
        cout << endl << list2.size() << endl;
        for(int num : list2) cout << num << " ";
        cout << endl;
    }

}

bool helper(int n, long target, vector<int> &temp, vector<int> &res){
    if(target == 0){
        res = temp;
        return true;
    }
    if(n == 0) return false;

    
    temp.push_back(n);
    bool inc = helper(n - 1, target - n, temp, res);
    temp.pop_back();
    if(inc) return true;
    bool exc = helper(n - 1, target, temp, res);
    return exc;
}

