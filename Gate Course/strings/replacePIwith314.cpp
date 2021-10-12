#include<bits\stdc++.h>
using namespace std;

string replaceWith314(string str){
    int n=str.length();
    string ans="";
    bool mark=false;
    for(int i=0;i<n-1;i++){
        if(str[i]=='p' && str[i+1]=='i'){
            ans+="3.14";
            mark=true;
        }
        else{
            if(!mark){
                ans+=str[i];
            }
            else{
                mark=false;
            }
        }
    }
    return ans;
}

void replaceWith314Rec(string str){
    if(str.length()==0){
        return;
    }
    if(str[0]=='p' && str[1]=='i'){
        cout<<"3.14";
        replaceWith314Rec(str.substr(2));
    }
    else{
        cout<<str[0];
        replaceWith314Rec(str.substr(1));
    }
}

int main(){
    string str;
    cin>>str;
    cout<<replaceWith314(str)<<endl;
    replaceWith314Rec(str);
}