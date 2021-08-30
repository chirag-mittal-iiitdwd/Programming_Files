#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string pushVal="";
        while(s[i]!=' ' && i<s.length()){
            pushVal+=s[i];
            i++;
        }
        st.push(pushVal);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main(){
    string s="Hey, how are you doing?";
    reverseSentence(s);

    return 0;
}