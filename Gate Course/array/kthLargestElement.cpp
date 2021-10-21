#include <bits/stdc++.h>
using namespace std;

int KthLargest(int arr[],int n,int k){
    set<int> s(arr, arr + n);
	auto itr = s.begin(); 
	advance(itr, k - 1);
    return *itr;
}

int kthLargest(int arr[],int n,int k){
    priority_queue<int, vector<int>, greater<int> >p;
    for(int i=0;i<n;i++){
        p.push(arr[i]);
    }

    for(int i=0;i<k-1;i++){
        p.pop();
    }
    return p.top();
}

int kthSmallest(int arr[],int l,int r,int k){
    priority_queue<int>mah(arr,arr+r+1);
    int toBeRem=r+1-k;
    for(int i=0;i<toBeRem;i++){
        mah.pop();
    }
    return mah.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<kthLargest(arr,n,k);
	return 0;
}
