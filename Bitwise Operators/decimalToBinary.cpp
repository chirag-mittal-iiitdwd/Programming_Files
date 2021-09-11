#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(double num,int k_prec){
    string binary="";
    int integral=num;
    double fractional1=num-integral;
    while(integral){
        int rem=integral%2;
        binary.push_back(rem+'0');
        integral/=2;
    }

    reverse(binary.begin(),binary.end());
    binary.push_back('.');
    while(k_prec--){
        fractional1*=2;
        int fract_bit=fractional1;
        if(fract_bit==1){
            fractional1-=fract_bit;
            binary.push_back(1+'0');
        }
        else{
            binary.push_back(0+'0');
        }
    }
    return binary;
}
int main(){
    double n = 4.47;
    int k = 3;
    cout << decimalToBinary(n, k) << "\n";
 
    n = 6.986 , k = 5;
    cout << decimalToBinary(n, k);
    return 0;
}