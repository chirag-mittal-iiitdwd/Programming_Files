#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str,str1;
        cin>>str>>str1;
        int gr=INT_MIN;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(str1[i]>str[i]){
                gr=str1[i];
                cnt++;
            }
            else{
                if(str1[i]>=str[i] && str[i]<gr){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}