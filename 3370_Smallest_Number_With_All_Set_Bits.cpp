#include <bits/stdc++.h>
using namespace std;

string decimal_to_binary(int decimal_num){
    string binary_string = "";
    while(decimal_num>0){
        binary_string += to_string(decimal_num % 2);
        decimal_num /=2;
    }
    reverse(binary_string.begin(),binary_string.end());
    return binary_string;
}

int binary_to_decimal(string binary){
    int val = 0;
    for(char c:binary){
        if(c!='0' && c!='1') continue;
        val = (val<<1) + (c - '0');
    }
    return static_cast<int>(val);
}

int main(){
    int deci_num = 10;
    string deci_to_bin_sol =  decimal_to_binary(deci_num);

    int bits_count = deci_to_bin_sol.size(); // size 

    string sol_in_bits = "";
    for(int i = 0;i<bits_count;i++){
        sol_in_bits.push_back('1');
    }

    // now convert this sol_in_bits to decimal
    int sol = binary_to_decimal(sol_in_bits);
    cout << sol << endl;
    return 0;
}