#include<bits/stdc++.h>
using namespace std;
bool sortedOrUnsorted(vector<int> arr,int idx){
    if(idx==arr.size()){
        return true;
    }
    if(arr[idx]>arr[idx+1]){
        return false;
    }
    return sortedOrUnsorted(arr,idx+1);
}

int main(){
    vector<int> arr={1,2,5,7,9};
    vector<int> arr1={1,3,4,2,11};
    cout<<sortedOrUnsorted(arr,0)<<endl;
    cout<<sortedOrUnsorted(arr1,0)<<endl;
    return 0;
}