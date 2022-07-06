#include<bits/stdc++.h>
using namespace std;

class SGtree{
    vector<int>seg;
    public:
    SGtree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            seg[idx]=arr[low];
            return;
        }

        int mid=(low+((high-low)/2));
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }

    // low and high are the array parameters, l and r are query parameters
    int query(int idx,int low,int high,int l,int r){
        // no overlap condition
        // l r low high or low high l r
        if(r<low || high<l){
            return INT_MAX;
        }

        // complete overlap condition
        // l low high r
        if(low>=l && high<=r){
            return seg[idx];
        }

        int mid=(low+((high-low)/2));
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }

    void update(int idx,int low,int high,int i,int val){
        if(low==high){
            seg[idx]=val;
        }
        int mid=(low+high)>>2;
        if(i<=mid){
            update(2*idx+1,low,mid,i,val);
        }
        else{
            update(2*idx+2,mid+1,high,i,val);
        }
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    SGtree seg1(n);
    seg1.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<seg1.query(0,0,n-1,l,r)<<endl;
        }
        else{
            int i,val;
            cin>>i>>val;
            seg1.update(0,0,n-1,i,val);
        }
    }
}

int main(){
    solve();
}