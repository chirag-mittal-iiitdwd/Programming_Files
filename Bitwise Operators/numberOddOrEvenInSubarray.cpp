#include<bits/stdc++.h>
using namespace std;

string substringOddOrEven(int arr[],int l,int r){
    int x=0;
    int sum=0;
    for(int i=l;i<=r;i++){
        sum+=(pow(2,x)*arr[i]);
        x++;
    }
    cout<<sum<<endl;
    if(sum%2){
        return "Odd";
    }
    else{
        return "Even";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l,r;
    cin>>l>>r;
    cout<<substringOddOrEven(arr,l,r)<<endl;
}