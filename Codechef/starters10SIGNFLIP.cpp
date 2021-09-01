#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        vector<int>negative;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<0){
                negative.push_back(arr[i]);
            }
            else{
                sum+=arr[i];
            }
        }
        sort(negative.begin(),negative.end());
        for(int i=0;i<k && i<negative.size();i++){
            negative[i]=-1*negative[i];
            sum+=negative[i];
        }
        cout<<sum<<endl;
    }
}