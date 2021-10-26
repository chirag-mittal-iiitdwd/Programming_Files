#include<bits/stdc++.h>
using namespace std;

struct cell{
    int row,col;
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        vector<cell>v(n);
        for(int i=0;i<n;i++){
            int r,c;
            cin>>r>>c;
            v[i].row=r;
            v[i].col=c;
        }

        sort(v.begin(),v.end(),[](cell a,cell b){
            return a.row<b.row;
        });

        int topToLeft=-1;
        for(i=1;i<n;i++){
            if(v[i].col==v[i-1].col-1){
                topToLeft=i;
            }
            else{
                break;
            }
        }

        int bottomToRight=-1;
        for(i=n-2;i>=0;i--){
            if(v[i].col==v[i+1].col+1){
                bottomToRight=i;
            }
            else{
                break;
            }
        }

        if(v[topToLeft].col==1 || v[bottomToRight].col==n){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}