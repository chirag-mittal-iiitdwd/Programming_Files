#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topEle=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topEle);
}

void reverseTheStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int topElem=st.top();
    st.pop();
    reverseTheStack(st);
    insertAtBottom(st,topElem);
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseTheStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}