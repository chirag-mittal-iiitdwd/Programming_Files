#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    vector<vector<int>>mat1(a,vector<int>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat1[i][j];
        }
    }

    vector<vector<int>>mat2(b,vector<int>(c));
    for(int i=0;i<b;i++){
        for(int j=0;j<c;j++){
            cin>>mat2[i][j];
        }
    }

    vector<vector<int>>ans(a,vector<int>(c));
    for(int i=0;i<a;i++){
        for(int j=0;j<c;j++){
            int prodVal=0;
            for(int k=0;k<b;k++){
                prodVal+=mat1[i][k]*mat2[k][j];
            }
            ans[i][j]=prodVal;
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<c;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}