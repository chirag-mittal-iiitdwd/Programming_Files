/*
    Brute force
    1.  Iterate from i=0 to i=n-k-1 in outer loop
    2.  starting from every j=i compute sum of k elements and maintain
        the minimum
    
    Time complexity - O(n*k)

    optimal solution (sliding window)
    1.  Compute the sum of first k elements (i=0 to k)
    2.  while increasing i, subtact a[i-1] and a[i-k-1] in the previous
        sum, while will became current sum.

    Time complexity - O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    int k=3;
    int arr[n]={-2,10,1,3,2,-1,4,5};
    int s=0,ans=INT_MAX;
    for(int i=0;i<k;i++){
        s+=arr[i];
    }
    ans=min(ans,s);
    for(int i=1;i<n-k+1;i++){
        s-=arr[i-1];
        s+=arr[i+k-1];
        ans=min(ans,s);
    }
    cout<<ans<<endl;
}