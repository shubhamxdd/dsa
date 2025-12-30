#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> nseArr(n);
    stack<int> st;

    for(int i = n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()) nseArr[i]=n;
        else nseArr[i] = st.top();
        st.push(i);
    }
    return nseArr;
}

vector<int> findPSE(vector<int> &arr){
    int n = arr.size();
    vector<int> pseArr(n);
    stack<int> st;

    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()) pseArr[i] = -1;
        else pseArr[i] = st.top();
        st.push(i);
    }
    return pseArr;
}

int largestArea(vector<int> &arr){
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    int maxArea = 0;
    for(int i = 0;i<n;i++){
        int area = arr[i] * (nse[i]-pse[i]-1);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}

int largestAreaBetter(vector<int> &arr){
    int n = arr.size();
    vector<int> nse(n); // right
    vector<int> pse(n); // left
    stack<int> st;

    // nse
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        nse[i]=st.empty() ? n:st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // pse
    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        pse[i] = st.empty() ? -1:st.top();
        st.push(i);
    }
    

    int maxArea = 0;
    for(int i = 0;i<n;i++){
        int area = arr[i] * (nse[i]-pse[i]-1); // height is arr[i] width is nse[i]-pse[i]-1
        maxArea = max(area,maxArea);
    }
    return maxArea;
}



int main(){
    vector<int> arr = {4,0,2,1,3};
    cout << largestAreaBetter(arr);
    // for(int iter:arr) cout << iter << " ";
    // cout << endl;
    // vector<int> nse = findNSE(arr);
    // for(int iter:nse) cout << iter << " ";
    // cout << endl;
    // vector<int> pse = findPSE(arr);
    // for(int iter:pse) cout << iter << " ";
    // cout << endl;
    return 0;
}