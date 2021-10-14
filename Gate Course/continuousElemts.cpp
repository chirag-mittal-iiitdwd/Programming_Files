#include<bits/stdc++.h>
using namespace std;

int makeContiNuous(int arr[],int n){
    sort(arr,arr+n);
    int operations=0;
    unordered_set<int>s;
    int maxi=arr[n-1];
    int mini=arr[0];
    int reqMax=mini+n-1;
    int toBeChanges=0;
    for(int i=0;i<n;i++){
        if(reqMax<arr[i]){
            toBeChanges++;
        }
        else{
            s.insert(arr[i]);
        }
    }
    operations+=(n-s.size()-toBeChanges);
    operations+=toBeChanges;

    return operations;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<makeContiNuous(arr,n);
}