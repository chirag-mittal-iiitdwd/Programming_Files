/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][n];
        if(n%2){
            // odd
            memset(arr,-1,sizeof(arr));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j==i){
                        arr[i][j]=1;
                    }
                }
            }
        }
        else{
            memset(arr,-1,sizeof(arr));
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}