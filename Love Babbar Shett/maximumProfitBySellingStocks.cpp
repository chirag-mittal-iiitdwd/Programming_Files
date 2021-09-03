#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int first=arr[0];
    int sum=0;
    for(int i=1;i<n;i++){
        if(first<arr[i]){
            sum+=(arr[i]-first);
        }
        first=arr[i];
    }
}