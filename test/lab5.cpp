#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        vector<int>negativeAndZero;
        vector<int>positive;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<0){
                negativeAndZero.push_back(arr[i]);
            }
            else{
                positive.push_back(arr[i]);
            }
        }
        for(auto it:positive){
            cout<<it<<" ";
        }
        cout<<endl;
        int sum=0;
        sort(negativeAndZero.begin(),negativeAndZero.end());
        for(int i=0;i<k;i++){
            negativeAndZero[i]=negativeAndZero[i]*-1;
            sum+=negativeAndZero[i];
        }
        for(auto it:positive){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0;i<positive.size();i++){
            sum+=positive[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}