#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool find3Numbers(int a[],int n,int x){
        sort(a,a+n);
        int l,r;
        for(int i=0;i<n-2;i++){
            l=i+1;
            r=n-1;
            while(l<r){
                if(a[i]+a[l]+a[r]==x){
                    return true;
                }
                else if(a[i]+a[l]+a[r]>x){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;
    cout<<ob.find3Numbers(arr,n,x)<<endl;
}