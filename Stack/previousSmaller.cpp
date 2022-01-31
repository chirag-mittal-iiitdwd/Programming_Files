#include<bits/stdc++.h>
using namespace std;

void previousSmaller(vector<int>arr){
    stack<int>st;
    int n=arr.size();

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            cout<<-1<<" ";
        }
        else{
            cout<<st.top()<<" ";
        }
        st.push(arr[i]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    previousSmaller(arr);
}