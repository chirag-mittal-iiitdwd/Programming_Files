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
        int x;
        cin>>x;
        int y=x%4;
        if(y==1){
            cout<<"East\n";
        }
        else if(y==2){
            cout<<"South\n";
        }
        else if(y==3){
            cout<<"West\n";
        }
        else{
            cout<<"North\n";
        }
    }
    return 0;
}