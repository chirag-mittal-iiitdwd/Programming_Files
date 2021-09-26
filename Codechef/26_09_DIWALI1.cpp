/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll p,a,b,c,x,y;
        cin>>p>>a>>b>>c>>x>>y;
        ll temp1=p,temp2=p;
        ll oneAnar=b+(a*x);
        ll oneChakri=c+(a*y);

        ll anar1=p/oneAnar;
        ll chakr1=p/oneChakri;

        temp1=temp1-(anar1*oneAnar);
        ll anar1plus=temp1/oneChakri;

        temp2=temp2-(chakr1*oneChakri);
        ll chakri1Plus=temp2/oneAnar;

        ll ans=max(anar1+anar1plus,chakr1+chakri1Plus);
        cout<<ans<<endl;
    }
    return 0;
}