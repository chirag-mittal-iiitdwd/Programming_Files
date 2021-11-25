#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int sum=0;
        int arr[n]={0};
        if(a[n-1]<b[n-1]){
            arr[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]<b[i]){
                arr[i]=1;
            }
            if(a[i]==b[i]){
                if(arr[i+1]==1){
                    arr[i]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}