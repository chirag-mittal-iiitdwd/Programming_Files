#include<bits/stdc++.h>
using namespace std;
class Solution{
    void heapify(vector<int> &a,int n,int i){
        int maxIdx=i;
        int leftChild=2*i+1;
        int rightChild=2*i+2;
        if(leftChild<n && a[leftChild]>a[maxIdx]){
            maxIdx=leftChild;
        }
        if(rightChild<n && a[rightChild]>a[maxIdx]){
            maxIdx=rightChild;
        }
        if(maxIdx!=i){
            swap(a[i],a[maxIdx]);
            heapify(a,n,maxIdx);
        }
    }
    public:
    void heapsort(vector<int> &a){
        int n=a.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(a,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(a[0],a[i]);
            heapify(a,i,0);
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    obj.heapsort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}