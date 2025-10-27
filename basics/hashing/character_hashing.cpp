#include <bits/stdc++.h>
using namespace std;


// take char and string as input to search
int char_freq(char charr, string s){
    int counter=0;

    for(int i=0;i < s.length();i++){
        if(s[i]== charr) counter++ ;
    }
    return counter;
}

int main(){
    // cout << char_freq('a',"abccaa") << endl;

    string s = "abcbcdds";


    int hash[26] = {0};

    for(int i=0;i <s.size();i++){
        hash[s[i]-'a']++;
    }

    int queries = 3;
    while(queries--){
        // take input of character to find frequency of
        char c;
        cout << "Give input: ";
        cin >> c;
        cout << hash[c-'a'] << endl;
    }




    // int aa = 'a'; // converts this to ascii 
    // int bb = 'f';

    // cout << bb-aa<<endl;



    return 0;
}