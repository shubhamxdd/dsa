#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLoopLL(Node *head)
{
    Node *temp = head;
    int timer = 1;
    map<Node *, int> mp;

    while (temp != nullptr)
    {
        // search if element exist in map
        timer++;

        auto elem = mp.find(temp);
        // means element exist
        if (elem != mp.end())
        {
            int val = mp[temp];
            return timer - val;
        }
        mp.insert({temp, timer});
        temp = temp->next;
    }
    return 0;
}

int lengthOfLoopLLOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    int count = 1;
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            slow = slow->next;
            while (slow != fast){
                count++;
                slow = slow->next;
            };
            return count;
        }
         // outside this while loop, both pointer will point to same element

        // then increase one pointer by one till it reaches it back
    }
    return 0;
}

int main()
{
    vector<int> arr = {4, 1, 2, 3};
    Node *head = convertArrtoLL(arr);
    // traverseLL(head);

    // int ans = lengthOfLoopLLOptimal(head);

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = head; // Loop formed

    int loopLength = lengthOfLoopLLOptimal(head);
    cout << "Length of loop: " << loopLength << endl;
    // Expected output: 4 (entire list is the loop)

    return 0;
}