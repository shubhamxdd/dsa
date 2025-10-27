#include <bits/stdc++.h>

// 4 parts of c++ STL => Algorithms, Containers, Function, Iterators

using namespace std;

void print(string name)
{
    cout << name << endl;
    // void doesnt return anything
}

int doubleNum(int a)
{
    return a * 2;
    // returns number multiplied by 2
}

void pairs()
{
    pair<int, int> firstPair = {1, 2};
    // cout << firstPair.first << " " << firstPair.second << endl;

    // nested pairs
    pair<int, pair<int, int>> nestedPair = {1, {3, 4}};
    // cout << nestedPair.first << endl;
    // cout << nestedPair.second.first << " " << nestedPair.second.second << endl;

    // array of pair

    pair<int, int> pairArr[] = {{1, 2}, {3, 4}, {5, 6}};

    for (int i = 0; i < 3; i++)
    {
        // cout << "First: " << pairArr[i].first << " Second: " << pairArr[i].second << endl;
    }
}

void vectorsLearn()
{
    vector<int> firstVec;
    firstVec.push_back(1);
    firstVec.push_back(2);
    firstVec.push_back(3);
    firstVec.emplace_back(4);

    for (int i = 0; i < firstVec.size(); i++)
    {
        // cout << firstVec[i] << endl;
    }
    vector<int> secondVector(5, 10); // => {10,10,10,10,10}
    for (int i = 0; i < secondVector.size(); i++)
    {
        // cout << secondVector[i] << endl;
    }

    // copy vector
    vector<int> vect(secondVector); // new container of copy

    // ITERATORS TO ACCESS VECTORS

    vector<int>::iterator iter = firstVec.begin();

    // cout << *iter << endl;

    // iter++;
    // cout << *iter << endl;

    // iter++;
    // cout << *iter << endl;

    // iter++;
    // cout << *iter << endl;

    // vector<int>::iterator it1 = firstVec.end();
    // it1--;
    // cout << *iter << endl;

    vector<int> newVec = {1, 2, 4, 5};
    cout << newVec.back();
}

void printVectors()
{
    vector<int> myVec = {1, 29, 8, 4, 435, 43, 5, 2};

    // first way
    for (vector<int>::iterator iter = myVec.begin(); iter != myVec.end(); iter++)
    {
        // cout << *iter << endl;
    }

    // second way

    for (auto iter = myVec.begin(); iter != myVec.end(); iter++)
    {
        // cout << *iter << endl;
    }

    // third way (forEach)
    for (auto iter : myVec)
    {
        cout << iter << endl;
    }
}

void eraseVectors()
{
    vector<int> myVec = {1, 2, 3, 4, 5, 6};

    // CONTINUE FROM HERE

    myVec.erase(myVec.begin() + 1, myVec.begin() + 3);

    for (auto iter : myVec)
    {
        cout << iter << endl;
    }
}

void insertVector()
{
    vector<int> myVec = {1, 2, 3, 4};

    myVec.insert(myVec.begin() + 2, 21);

    for (auto iter = myVec.begin(); iter != myVec.end(); iter++)
    {
        cout << *iter << endl;
    }
    // myVec.pop_back() // pops last element of vector
    // myVec.clear()// clears vector

    cout << myVec.size() << endl; // gives size of vector
}

void lists()
{
    // almost same as vectors
}
void deques()
{
    // almost same as vectors
}

void stacks()
{
    // LIFO
    // not accessible with index
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(4); // {4, 3, 2, 1}

    // st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    // stack<int> newStack;
    // newStack.swap(st);
}

void queues()
{
    // FIFO

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.back() += 2;  // adds 2 to element on back
    q.front() += 2; // adds 2 to element on front

    q.pop(); // removes element on 0th index

    cout << q.front() << endl;
    cout << q.back() << endl;
}

void priority_queues()
{
    priority_queue<int> pq;
    // largest element stays on top
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(2);
}

void setss()
{
    // stores in sorted order and unique elements
    set<int> mySet;
    mySet.insert(1); // {1}
    mySet.insert(2); // {1,2}
    mySet.insert(2); // {1,2}
    mySet.insert(4); // {1,2,4}
    mySet.insert(3); // {1,2,3,4}

    auto iter = mySet.find(2); // returns iterator
    mySet.erase(2);            // removes 2
}

void mapss()
{
    // stores unique keys in sorted order
    map<int, int> myMap;
    myMap.insert({1, 2});

    for (auto pair : myMap)
    {
        cout << pair.first << endl;
        cout << pair.second << endl;
    }

    // multimap => duplicate keys can be stored
}


bool comp(pair<int, int> pair1, pair<int, int> pair2) {
    if(pair1.second>pair2.second) return false;
    if(pair1.second<pair2.second) return true;

    if(pair1.first>pair2.first) return true;
    return false;

}

void extraa()
{
    // array<int, 6> myArr = {8, 4, 5, 9, 2, 5};

    // sort(myArr.begin(), myArr.end()); // sort in increasing order

    // for (int i = 0; i < myArr.size(); i++)
    // {
    //     cout << myArr[i] << endl;
    // }

    // sort pair

    pair<int, int> mypair[] = {{1, 2}, {2, 1}, {4, 1}};


    sort(mypair, mypair + 3, comp);
}

int main()
{
    // print("shubham");
    // int sol = doubleNum(4);
    // cout << sol;
    // pairs();
    // vectorsLearn();
    // printVectors();
    // eraseVectors();
    // insertVector();
    // lists();
    // deques();
    // stacks();
    // queues();
    // priority_queues();
    // setss();
    // mapss();
    extraa();
    return 0;
}