#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
 
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    
    bool flag = false;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
 
        if(flag) cout << curr << " ";
        else q.push(curr);
 
        flag = !flag;
    }
 
    cout << "\n";
}
 

/* solution using linked list
class Node{
    public:
        int val;
        Node* next;

        Node(){
            this->val = val;
            this->next = nullptr;
        }
        Node(int val){
            this->val = val;
            this->next = nullptr;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    Node *dummy = new Node(-1);
    Node *tail = dummy;
    for(int i = 1; i <= n; i++){
        tail->next = new Node(i);
        tail = tail->next;
    }
    Node *head = dummy->next;
    tail->next = head;
    

    while(head != nullptr){
        if(head->next == head){
            cout << head->val << " ";
            break;
        }
        cout << head->next->val << " ";
        head->next = head->next->next;
        head = head->next;
    }
    cout << "\n";
}

*/