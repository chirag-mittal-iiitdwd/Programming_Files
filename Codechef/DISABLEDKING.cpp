/*
    
*/
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
        int n;
        cin>>n;
        int steps=0;
        int goUpto=(n/2)+1;
        if(n%2){
            steps+=(2*(goUpto-1));
        }
        else{
            steps+=goUpto;
            steps+=(goUpto-2);
        }
        cout<<steps<<endl;
    }
    return 0;
}