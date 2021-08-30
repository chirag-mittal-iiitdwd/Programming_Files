// https://www.youtube.com/watch?v=UVW0NfG_YWA&list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p&index=32

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// n is the end index and i is the starting index
void heapify(vector<int> &a,int n,int i){
    int maxIdx=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    // if left child exists = bascilly greater than element at maxIdx
    // Than update maxIdx
    // Check same for right child
    // In order to confirm maxIdx is at which element parent, left or right
    if(leftChild<n && a[leftChild]>a[maxIdx]){
        maxIdx=leftChild;
    }
    if(rightChild<n && a[rightChild]>a[maxIdx]){
        maxIdx=rightChild;
    }
    // Now we have swap only when maxIdx is not the parent
    if(maxIdx!=i){
        swap(a[i],a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}

void heapsort(vector<int> &a){
    int n=a.size();
    // Loop from last non leaf element than 
    // call heapify so it will convert to maxHeap
    // The first non-leaf node is n/2-1
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    // Pick last element and swap
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapsort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}