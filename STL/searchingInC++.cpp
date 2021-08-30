#include<bits/stdc++.h>
using namespace std;
int main(){
    // The array must be sorted while applying this

    int a[]={1,4,5,8,9};
    // Binaray search returns 0 or 1 depending upon the availablity
    bool res=binary_search(a,a+5,3);
    bool res1=binary_search(a,a+5,4);
    cout<<res<<" "<<res1<<endl;

    int arr[]={1,4,5,6,9,9};
    // points to the next gratest element or the element itself
    // For element which is out of bound it return size+1
    int index=lower_bound(arr,arr+6,4)-arr;
    int index1=lower_bound(arr,arr+6,10)-arr;
    int index2=lower_bound(arr,arr+6,7)-arr;
    int index3=lower_bound(arr,arr+6,1000)-arr;
    cout<<index<<" "<<index1<<" "<<index2<<" "<<index3<<endl;

    // Gives the index of next gratest element
    // Can be used to find the last occurance of an element
    int idx=upper_bound(arr,arr+6,4)-arr;
    int idx1=upper_bound(arr,arr+6,10)-arr;
    int idx2=upper_bound(arr,arr+6,7)-arr;
    int idx3=upper_bound(arr,arr+6,1000)-arr;
    cout<<idx<<" "<<idx1<<" "<<idx2<<" "<<idx3<<endl;
}