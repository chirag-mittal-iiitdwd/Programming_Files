#include<bits\stdc++.h>
using namespace std;

string moveallX(string x){
    if(x.length()==0){
        return "";
    }
    char ch=x[0];
    string ans=moveallX(x.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}

string moveAllXIter(string str){
    string ans="";
    string x="";
    int n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='x'){
            x=x+'x';
        }
        else{
            ans+=str[i];
        }
    }
    return ans+x;
}

int main(){
    string str="abxxcdxx";
    cout<<moveallX(str)<<endl;
    cout<<moveAllXIter(str)<<endl;
}