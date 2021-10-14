#include<bits\stdc++.h>
using namespace std;

// This function is derived from the maximum area in histogram
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

int maxAreaRectange(vector<vector<int>>mat,int r,int c){
    vector<int>height(c);
    for(int i=0;i<c;i++){
        height[i]=mat[0][i];
    }

    int maxA=INT_MIN;
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==0){
                height[j]=0;
            }
            else{
                height[j]++;
            }
        }
        maxA=max(maxA,findMax(height));
    }

    return maxA;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<maxAreaRectange(mat,r,c)<<endl;
}