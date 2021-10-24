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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>zero,one;
        for(int i=0;i<n;i+=2){
            zero.push_back(arr[i]);
        }
        for(int i=1;i<n;i+=2){
            one.push_back(arr[i]);
        }
        sort(one.begin(),one.end());
        sort(zero.begin(),zero.end(),greater<int>());

        int zeroCnt=0;
        int oneCnt=0;
        for(int i=0;i<n;i++){
            if((i%2)==0){
                arr[i]=zero[zeroCnt];
                zeroCnt++;
            }
            else{
                arr[i]=one[oneCnt];
                oneCnt++;
            }
        }

        int sum=0;
        zeroCnt=0;
        for(int i=0;i<zero.size();i++){
            sum+=(zero[zeroCnt]*accumulate(one.begin()+zeroCnt,one.end(),0));
            zeroCnt++;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<sum<<endl;
    }
    return 0;
}