#include <bits/stdc++.h>
using namespace std;


bool linearSearch(vector<int> arr, int num){
    for (int i = 0; i < arr.size(); i++){
        if(arr[i]==num){
            return true;
        }
    }
    return false;
    
}

int brute(vector<int> arr){
    int count = 1;
    int largest = 1;
    int num = 0;
    for(int i = 0;i<arr.size();i++){
        num=arr[i];
        count = 1;
        while(linearSearch(arr,num+1)){
            num=num+1;
            count++;
        }
        largest = max(largest,count);
    }
    return largest;
}

int optimal(vector<int> arr){
    if(arr.size()==0) return 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i = 0;i<arr.size();i++){
        st.insert(arr[i]);
    }
    for(auto iter:st){
        if(st.find(iter-1)==st.end()){
            int count = 1;
            int x = iter;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}



int main(){
    vector<int> arr = {102,4,100,1,101,3,2,1,1};
    // vector<int> arr = {1,0,1,2};
    cout << optimal(arr) << endl;
    return 0;
}