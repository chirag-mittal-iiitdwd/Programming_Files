#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lowIdx=floor(sqrt(n));
        int intValOfHigh=sqrt(n);
        float floatValOfHigh=sqrt(n);
        int low=pow(2,lowIdx);
        int high;
        cout<<intValOfHigh<<" "<<floatValOfHigh<<endl;
        if(intValOfHigh==floatValOfHigh){
            cout<<"exe"<<endl;
            high=pow(2,lowIdx);
        }
        else{
            high=pow(2,lowIdx)-1;
        }
        // cout<<"low : "<<low<<endl;
        // cout<<"high : "<<high<<endl;
        int mid=(high+low)/2;
        int startIdx=low/2;
        if(n<=mid){
            cout<<n<<" : "<<startIdx<<endl;
        }
        else if(n>mid){
            cout<<n<<" : "<<startIdx+(n-mid)<<endl;
        }
    }
    return 0;
}