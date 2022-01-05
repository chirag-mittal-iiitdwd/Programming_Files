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
        int n,k;
        cin>>n>>k;
        int maxk=0;
        if(n&1){
            maxk=((n/2)+1);
        }
        else{
            maxk=n/2;
        }
        if(k<=maxk){

            char arr[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arr[i][j]='.';
                }
            }
            int cnt=0;
            for(int i=0;i<n;i+=2){
                arr[i][i]='R';
                cnt++;
                if(cnt==k){
                    break;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<arr[i][j];
                }
                cout<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}