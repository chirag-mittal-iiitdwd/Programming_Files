
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
        int cnt=0;
        string a="";
        string b="";
        for(int i=n-1;i>=0;i--){
            a=str[i]+a;
            b=str1[i]+b;
            cnt+=lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
        }
        cout<<cnt<<endl;
    }
    return 0;
}