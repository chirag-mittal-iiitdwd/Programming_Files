#include<bits/stdc++.h>
using namespace std;

 int main(){
    string str;
    cin>>str;
    string dup=str;
    reverse(dup.begin(),dup.end());
    if(dup==str){
        cout<<"yes"<<endl;
    }
 }