#include<bits/stdc++.h>
using namespace std;

vector<string> substrings(string str){
    int n=str.length();
    vector<string>ans;
    ans.push_back(" ");
    for(int i=0;i<n;i++){
        string x="";
        for(int j=i;j<n;j++){
            x+=str[j];
            ans.push_back(x);
        }
    }
    return ans;
}

void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<" ";
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}

int main(){
    string str;
    cin>>str;
    string ans1="";
    vector<string>ans=substrings(str);
    for(auto it:ans){
        for(int i=0;i<it.length();i++){
            cout<<it[i];
        }
        cout<<" ";
    }
    cout<<endl;
    subseq(str,ans1);
}