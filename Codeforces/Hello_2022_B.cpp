#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int size=1e9;
int arr[(int)1e9];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<size;i++){
            arr[i]=INT_MAX;
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int l,r,c;
            cin>>l>>r>>c;
            for(int j=l;j<=r;j++){
                arr[j]=min(arr[j],c);
            }
        }
    }
    return 0;
}