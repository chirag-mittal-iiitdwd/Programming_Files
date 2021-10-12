#include<bits\stdc++.h>
using namespace std;

void reverseRecursive(string str){
    if(str.length()==0){
        return;
    }
    string ros=str.substr(1);
    cout<<ros<<endl;
    reverseRecursive(ros);
    cout<<str[0];
}

int main(){
    string str;
    cin>>str;
    reverseRecursive(str);
}