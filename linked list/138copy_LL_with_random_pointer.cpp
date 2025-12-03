#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head){
    Node *temp = head;
    map<Node *, Node *> mp;

    while (temp){
        Node *newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp){
        Node *copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}