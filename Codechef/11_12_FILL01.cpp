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
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int cnt=0;
        int i=0;
        int j;
        while(i<n){
            if(str[i]=='0'){
                j=i;
                while(j<k+i){
                    if(j>n||str[j]=='1'){
                        break;
                    }
                    j++;
                }
                if(k==j-i){
                    cnt++;
                    i+=k;
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}