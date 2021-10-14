#include<bits\stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>&height){
    int n=height.size();
    stack<int>st;
    int leftSmall[n],rightSmall[n];
    for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            leftSmall[i]=0;
        }
        else{
            leftSmall[i]=st.top()+1;
        }
        st.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            rightSmall[i]=n-1;
        }
        else{
            rightSmall[i]=st.top()-1;
        }
        st.push(i);
    }
    int maxA=0;
    for(int i=0;i<n;i++){
        maxA=max(maxA,height[i]*(rightSmall[i]-leftSmall[i]+1));
    }
    return maxA;
}

int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<largestRectangleArea(height)<<endl;
}