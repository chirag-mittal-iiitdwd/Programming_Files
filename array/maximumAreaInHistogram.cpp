#include<bits/stdc++.h>
using namespace std;

int maximumAreaInHist(vector<int>height){
    int leftSmaller[height.size()];
    int rightSmaller[height.size()];
    stack<int>st;
    for(int i=0;i<height.size();i++){
        while(!st.empty()&&height[i]<height[st.top()]){
            st.pop();
        }
        if(st.empty()){
            leftSmaller[i]=0;
        }
        else{
            leftSmaller[i]=st.top()+1;
        }
        st.push(i);
    }

    for(int i=height.size()-1;i>=0;i--){
        if(!st.empty()&&height[i]<height[st.top()]){
            st.pop();
        }
        if(st.empty()){
            rightSmaller[i]=height.size()-1;
        }
        else{
            rightSmaller[i]=st.top()-1;
        }
        st.push(i);
    }
    int ans=INT_MIN;
    for(int i=0;i<height.size();i++){
        ans=max(ans,(rightSmaller[i]-leftSmaller[i]+1)*height[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximumAreaInHist(arr);
}