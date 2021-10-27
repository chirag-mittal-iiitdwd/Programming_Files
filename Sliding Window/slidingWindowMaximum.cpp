#include<bits/stdc++.h>
using namespace std;

vector<int>slidingWindowMaximum(vector<int>arr,int n,int k){
    vector<int>ans;
    deque<int>dq;
    for(int i=0;i<k;i++){
        dq.push_back(arr[i]);
    }
    cout<<endl;
    ans.push_back(*max_element(dq.begin(),dq.end()));
    for(int i=1;i<n-k+1;i++){
        dq.pop_front();
        dq.push_back(arr[i+k-1]);
        ans.push_back(*max_element(dq.begin(),dq.end()));
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>x=slidingWindowMaximum(arr,n,k);
    for(auto it:x){
        cout<<it<<" ";
    }
    cout<<endl;
}