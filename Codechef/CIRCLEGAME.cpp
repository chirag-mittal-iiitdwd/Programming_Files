#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m,x;
        cin>>m>>x;
        if(m==1){
            for(int i=1;i<=x;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            int i=1;
            int arr[x+1];
            while((i)!=(m-1)){
                arr[i]=(m%i)+1;
                i++;
            }
            if((m&1)==0 && i==m-1){
                arr[i]=2;
                i++;
            }
            while(i<=x){
                arr[i]=m-1;
                i++;
            }
            for(int i=1;i<=x;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}