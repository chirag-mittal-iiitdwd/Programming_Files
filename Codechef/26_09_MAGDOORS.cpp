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
        string str;
        cin>>str;
        int currentStatus=str[0];
        int n=str.length();
        int wandWaved=0;
        if(currentStatus=='0'){
            wandWaved++;
        }
        for(int i=1;i<n;i++){
            if(currentStatus!=str[i]){
                wandWaved++;
                currentStatus=str[i];
            }
        }
        cout<<wandWaved<<endl;
    }
    return 0;
}