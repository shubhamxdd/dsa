#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &charArr){
    // idx points to start of new character
    int idx = 0;
    // loop over char arr
    for(int i = 0;i<charArr.size();i++){
        char ch = charArr[i];
        int count = 0;
        // count number of times a character apperas
        while(i<charArr.size() && charArr[i]==ch){
            count++;
            i++;
        }
        if(count == 1) {
            charArr[idx++]=ch;
        }else {
            // count > 1
            charArr[idx++]=ch;
            // convert count to string
            string count_string = to_string(count);
            for(char digitStr:count_string){
                charArr[idx++] = digitStr;
            }
        } 
        i--;
    }
    charArr.resize(idx);
    return idx;
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << compress(chars);
    return 0;
}