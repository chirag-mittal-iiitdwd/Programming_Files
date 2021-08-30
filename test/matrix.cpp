#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        char arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=0;
            }
        }
        int ansA=0,ansB=0,ans=0;
        for(int i=0;i<n*m;i++){
            cin>>x>>y;
            if(i==0){
                arr[x-1][y-1]='A';
            }
            else if(i%2==1){
                arr[x-1][y-1]='B';
            }
            else{
                arr[x-1][y-1]='A';
            }
        }
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                ansA=0;
                ansB=0;
                for(int p=i;p<k+i;p++){
                    for(int q=j;q<k+j;q++){
                        if(arr[p][q]=='A'){
                            ansA++;
                        }
                        if(arr[p][q]=='B'){
                            ansB++;
                        }
                    }
                }
                if(ansA==k*k){
                    ans=1;
                    break;
                }
                if(ansB==k*k){
                    ans=2;
                    break;
                }
            }
        }
        if(ans==1){
            cout<<"Alice"<<endl;
        }
        else if(ans==2){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}