#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    int numberOfBits=log2(res)+1;
    int pos=0;

    // Calculating rightmost set bit
    for(int i=0;i<numberOfBits;i++){
        if((res&(1<<i))==1){
            break;
        }
        pos++;
    }
    vector<int> v1;
    vector<int> v2;

    // separating both of them into both parts based on
    // the setbit at that poition
    for(int i=0;i<n;i++){
        if((arr[i]&(1<<pos))==1){
            v1.push_back(arr[i]);
        }
        else{
            v2.push_back(arr[i]);
        }
    }
    int ans1=res;
    int ans2=res;
    for(int i=0;i<v1.size();i++){
        ans1=ans1^v1[i];
    }
    for(int i=0;i<v2.size();i++){
        ans2=ans2^v2[i];
    }
    cout<<ans1<<" "<<ans2<<endl;
}