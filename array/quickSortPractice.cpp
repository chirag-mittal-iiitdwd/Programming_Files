#include<bits/stdc++.h>
using namespace std;
class quickSort{
    int partition(int l,int r,int arr[]){
        int i=l,j=r,pivot=arr[l];
        while(i<j){
            while(arr[i]<=pivot){
                i++;
            }
            while(arr[j]>=pivot){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        // Now j is standing at the first smallest element from the end
        swap(arr[j],arr[l]);
        return j;
    }
    public:
    void sortTheArray(int arr[],int l,int r){
        if(l<r){
            int pivot=partition(l,r,arr);
            sortTheArray(arr,l,pivot-1);
            sortTheArray(arr,pivot+1,r);
        }
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort obj;
    obj.sortTheArray(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}