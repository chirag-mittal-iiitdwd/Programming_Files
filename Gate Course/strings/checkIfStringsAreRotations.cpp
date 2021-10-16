#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,str1;
    getline(cin,str);
    getline(cin,str1);

    reverse(str.begin(),str.end());

    cout<<str<<endl;
    cout<<str1<<endl;
    if(str==str1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}