#include<iostream>
using namespace std;

bool checkAnswer(int n,int x,int k){
    bool ans=false;
    for(int i=0;i<=n+1;i=i+k){
        if(i==x){
            ans=true;
            break;
        }
    }
    if(ans==true){
        return ans;
    }
    else{
        for(int i=(n+1);i>=0;i=i-k){
            if(i==x){
                ans=true;
                break;
            }
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n=0;
        int x=0;
        int k=0;
        cin>>n>>x>>k;
        if(checkAnswer(n,x,k)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}