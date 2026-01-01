#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int key,val;
        Node *prev;
        Node *next;

        Node(int k, int v){
            key=k;
            val=v;
            prev=next=nullptr;
        }
};

class LRUCache {
    public:
        Node* head = new Node(-1,-1);
        Node *tail = new Node(-1,-1);
        unordered_map<int, Node*> mp;
        int limit;

        void deleteNode(Node *oldNode){
            Node *oldPrev= oldNode->prev;
            Node *oldNext = oldNode->next;

            oldPrev->next=oldNext;
            oldNext->prev = oldPrev;

            // oldNode->next=nullptr;
            // oldNode->prev=nullptr;

            // delete oldNode;
        }
        void insertNode(Node *newNode){
            Node *oldNext = head->next;

            head->next=newNode;
            oldNext->prev=newNode;

            newNode->next=oldNext;
            newNode->prev=head;
        }


        LRUCache(int capacity){
            limit=capacity;
            // connect head and tail
            head->next=tail;
            tail->prev=head;
        }

        void put(int key, int val){
            // 1. check if key already exist in map or not
            if(mp.find(key) != mp.end()){
                // it exists
                deleteNode(mp[key]);
                mp.erase(key);
            }
            // 2. check if capacity reached
            if(limit == mp.size()){
                // delete LRU element deleteNode(tail->prev)
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            // 3. insert node
            Node *newNode = new Node(key,val);
            // insertNode(head->next)
            insertNode(newNode);
            mp[key] = newNode;
            
        }
        int get(int key){
            if(mp.find(key) == mp.end()) return -1;
            // key exist
            Node *ansNode = mp[key];
            int ans = ansNode->val;

            mp.erase(key);
            deleteNode(ansNode);
            
            insertNode(ansNode);
            mp[key]=ansNode;
            
            return ans;
        }
};

int main(){
    LRUCache lru = LRUCache(2);
    lru.put(1,1);
    lru.put(2,2);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    lru.put(3,3);
    lru.put(4,4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    return 0;
}