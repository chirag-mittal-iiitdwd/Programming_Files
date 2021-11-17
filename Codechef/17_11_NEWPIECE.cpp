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
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        int sum1=a+b;
        int sum2=x+y;
        if(a==x && b==y){
            cout<<0<<endl;
        }
        else if((sum1%2 && sum2%2)||(sum1%2==0 && sum2%2==0)){
            cout<<2<<endl;
        }
        else if((sum1%2 && sum2%2==0)||(sum1%2==0 && sum2%2)){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}