#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        vector<int> tree;
        int n;
    public:
        SegmentTree(){};
        void build(vector<int> &nums, int n){
            tree.resize(4 * n, 0);
            build(nums, 1, 0, n - 1);
            this->n = n;
        }
        int sum(int l, int r){
           return sum(1, 0, n - 1, l, r);
        }
        void update(int pos, int val){
            update(1, 0, n - 1, pos, val);
        }
        
    private:
        void build(vector<int> &nums, int v, int l, int r){
            if(l > r) return;
            if(l == r){
                tree[v] = nums[l];
                return;
            }
            int mid = (l + r) / 2;
            build(nums, 2 * v, l, mid);
            build(nums, 2 * v + 1, mid + 1, r);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
        int sum(int v, int l, int r, int ql, int qr){
            if(l > r) return 0;
            if(l == ql && r == qr){
                return tree[v];
            }
            int mid = (l + r) / 2;
            if (qr <= mid)
                return sum(2 * v, l, mid, ql, qr);
            if (ql > mid)
                return sum(2 * v + 1, mid + 1, r, ql, qr);
            
            return sum(2 * v, l, mid, ql, mid) + sum(2 * v + 1, mid + 1, r, mid + 1, qr);
        }

        void update(int v, int l, int r, int pos, int new_val){
            if(l == r){
                tree[v] = new_val;
                return;
            }

            int mid = (l + r) / 2;
            if(pos <= mid){
                update(2*v, l, mid, pos, new_val);
            }
            else{
                update(2*v + 1, mid + 1, r, pos, new_val);
            }
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
};