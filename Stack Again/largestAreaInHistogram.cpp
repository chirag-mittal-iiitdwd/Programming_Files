#include<bits/stdc++.h>
using namespace std;

int bruteForceSolution(vector<int>arr){
    int ans=0,n=arr.size();
    for(int i=0;i<n;i++){
        int minh=INT_MAX;
        for(int j=i;j<n;j++){
            minh=min(arr[j],minh);
            int len=j-i+1;
            ans=max(ans,len*minh);
        }
    }
    return ans;
}

int findMax(vector<int>height){
    int n=height.size();
    int leftSmall[n],rightSmall[n];
    stack<int>st;
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
    int maxA=INT_MIN;
    for(int i=0;i<n;i++){
        maxA=max(maxA,height[i]*(rightSmall[i]-leftSmall[i]+1));
    }
    return maxA;
}

int findMaxArea(vector<int>a){
    int n=a.size(),ans=0,i=0;
    stack<int>st;
    a.push_back(0);
    while(i<n){
        while(!st.empty() && a[st.top()]>a[i]){
            // Here some rectange can be formed
            int t=st.top();
            int h=a[t]; // height of rectange
            st.pop();
            if(st.empty()){
                // This means this is the smallest height of all
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
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
    cout<<findMax(arr)<<endl;
}