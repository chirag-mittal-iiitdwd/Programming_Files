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
        int x,y,p,q;
        cin>>x>>y>>p>>q;
        int chef=x+(10*p);
        int chefina=y+(q*10);
        // cout<<chef<<" "<<chefina<<endl;
        if(chef==chefina){
            cout<<"Draw\n";
        }
        else if(chef<chefina){
            cout<<"Chef\n";
        }
        else{
            cout<<"Chefina\n";
        }
    }
    return 0;
}