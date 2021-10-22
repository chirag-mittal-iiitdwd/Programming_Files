/*
    if(arr[i]>arr[j] && i<j)  ---> inversions++;
    If in any problem you want to check all pairs in lowest complexity than go for merge sort

    Time Complexity : O(N logN)
    Space Complexity : O(N)
*/

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>p;
int getInversions(int arr[],int l,int r,int mid){
    int inversions=0;
    // l=0, mid=3, k=0,i=0,j=4
    int b[l+r+1],i=l,k=l,j=mid+1;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            b[k]=arr[j];
            inversions+=(mid-l+1-i);
            p.push_back({arr[i],arr[j]});
            p.push_back({arr[j],arr[i]});
            p.push_back({arr[j],arr[j]});
            k++;
            j++;
        }
        else{
            p.push_back({arr[i],arr[j]});
            p.push_back({arr[j],arr[i]});
            p.push_back({arr[i],arr[i]});
            b[k]=arr[i];
            i++;
            k++;
        }
    }

    while(i<=mid){
        b[k]=arr[i];
        p.push_back({arr[i],arr[i]});
        i++;
        k++;
    }
    while(j<=r){
        b[k]=arr[j];
        p.push_back({arr[j],arr[j]});
        j++;
        k++;
    }

    for(int x=l;x<=r;x++){
        arr[x]=b[x];
    }
    return inversions;
}

int countInversion(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        return countInversion(arr,l,mid)+countInversion(arr,mid+1,r)+getInversions(arr,l,r,mid);
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countInversion(arr,0,n-1)<<endl;
    for(auto it:p){
        cout<<it.first<<" "<<it.second<<endl;
    }
}