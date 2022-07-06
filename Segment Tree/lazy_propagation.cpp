#include<bits/stdc++.h>
using namespace std;

class ST{
    vector<int>st,lazy;
    public:
    ST(int n){
        st.resize(4*n);
        lazy.resize(4*n);
    }
    
    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            st[idx]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        st[idx]=st[2*idx+1]+st[2*idx+2];
    }

    void update(int idx,int low,int high,int l,int r,int val){
        if(lazy[idx]!=0){
            st[idx]+=(high-low+1)*lazy[idx];
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }

        // no overlap --> return ( low high l r ) or ( l r low high )
        if(high<l || r<low){
            return;
        }

        // complete overlap --> l low high r
        if(low>=l && high<=r){
            st[idx]+=(high-low+1)*val;
            if(low!=high){
                lazy[2*idx+1]+=val;
                lazy[2*idx+2]+=val;
            }
            return;
        }

        int mid=(high+low)/2;
        update(2*idx+1,low,mid,l,r,val);
        update(2*idx+2,mid+1,high,l,r,val);
        st[idx]=st[2*idx+1]+st[2*idx+2];
    }

    int query(int idx,int low,int high,int l,int r){
        if(lazy[idx]!=0){
            st[idx]+=(high-low+1)*lazy[idx];
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }
        
        if(high<l || r<low){
            return 0;
        }

        // complete overlap
        if(low>=l && high<=r){
            return st[idx];
        }

        int mid=(low+high)/2;
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);
        return left+right;
    }
};