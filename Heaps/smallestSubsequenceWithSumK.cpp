// We aaplied greedy approach here
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,1,3,2,8};
    int k=13;
    int n=5;
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int sum=0;
    int count=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
        count++;
        if(sum>=k){
            break;
        }
    }
    if(sum<k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<count<<endl;
    }
}