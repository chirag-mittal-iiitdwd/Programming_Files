#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution{
    public:
    int getOddOccurrence(int n,int arr[]){
        int res=0;
        for(int i=0;i<n;i++){
            res=res^arr[i];
        }
        return res;
    }
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;
    cout<<ob.getOddOccurrence(n,arr)<<endl;
    return 0;
}