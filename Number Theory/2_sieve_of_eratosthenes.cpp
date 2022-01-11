#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(N.LogLogN)
bool arr[1000001];
void sieve(){
    int maxN=1000001;
    arr[0]=arr[1]=true;
    for(int i=2;i*i<=maxN;i++){
        if(arr[i]==false){
            for(int j=i*i;j<=maxN;j+=i){
                arr[j]=true;
            }
        }
    }
}

int main(){
    sieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(!arr[n]){
            cout<<n<<" is prime"<<endl;
        }
        else{
            cout<<n<<" is not prime"<<endl;
        }
    }
}