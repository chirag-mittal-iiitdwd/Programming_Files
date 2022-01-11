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
        string str;
        cin>>str;
        string ans{""};
        if(n==1){
            ans=str[0];
            ans+=str[0];
        }
        else if(str[1]==str[0]){
            ans=str[0];
            ans+=str[0];
        }
        else{
            int i=1;
            while(i<n){
                if(str[i]>str[i-1]){
                    break;
                }
                i++;
            }
            ans=str.substr(0,i);
            string ans2=ans;
            reverse(ans2.begin(),ans2.end());
            ans+=ans2;
        }
        cout<<ans<<endl;
    }
    return 0;
}