#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int largestRectangleArea(vector<int>height){
        int n=height.size();
        vector<int>leftSm(n);
        vector<int>rightSm(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }

            if(st.empty()){
                leftSm[i]=0;
            }
            else{
                leftSm[i]=st.top()+1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }

            if(st.empty()){
                rightSm[i]=n-1;
            }
            else{
                rightSm[i]=st.top()-1;
            }
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,height[i]*(rightSm[i]-leftSm[i]+1));
        }
        return ans;
    }
};

class Solution{
    int largestRectangleArea(vector<int>arr){
        int n=arr.size(),maxi=0;
        stack<int>st;

        for(int i=0;i<=n;i++){
            while(!st.empty() && ((i==n)||(arr[st.top()]>=arr[i]))){
                int h=arr[st.top()];
                st.pop();
                int width=0;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                maxi=max(maxi,h*width);
            }
            st.push(i);
        }

        return maxi;
    }
};