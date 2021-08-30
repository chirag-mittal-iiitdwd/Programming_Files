#include<iostream>
#include<stack>
using namespace std;
int main(){
    bool ans=true;
    stack<char> st;
    string s;
    getline(cin,s);
    int i=0;
    while(s[i]!='X'){
        st.push(s[i]);
        i++;
    }
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    cout<<s.length()<<endl;
    while(s[i]){
        int topEle=st.top();
        if(topEle!=s[i]){
            ans=false;
            break;
        }
        st.pop();
        i++;
    }

    cout<<ans;
}