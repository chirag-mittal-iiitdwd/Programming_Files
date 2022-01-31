#include<bits/stdc++.h>
using namespace std;

int findXOR(vector<int>arr){
    int maxi=0;
    for(int i=1;i<arr.size();i++){
        maxi=max(maxi,arr[i-1]^arr[i]);
    }
    return maxi;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=1;i<=n;i++){
            arr[i-1]=i-1;
        }

        int mini=INT_MAX;

        do{
            int cur=findXOR(arr);
            if(mini>cur){
                mini=cur;
                cout<<"mini : "<<mini<<endl;
                for(auto&it:arr){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }while(next_permutation(arr.begin(),arr.end()));

        cout<<"ended"<<endl;
    }
}