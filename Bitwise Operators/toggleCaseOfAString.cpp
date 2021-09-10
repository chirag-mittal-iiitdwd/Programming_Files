#include<bits/stdc++.h>
using namespace std;

string toggleCase(string str){
    for(int i=0;i<str[i]!='\0';i++){
        str[i]=(str[i]^32);
    }
    return str;
}
int main(){
    string str="GeekSfOrgEEKs";
    cout<<toggleCase(str);
}