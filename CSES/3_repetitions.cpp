#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    int n=str.length();
    char cur=str[0];
    int cnt=1;
    int mxCnt=0;

    for(int i=1;i<n;i++){
        if(str[i]==cur){
            cnt++;
        }
        else{
            if(cnt>mxCnt){
                mxCnt=cnt;
            }
            cur=str[i];
            cnt=1;
        }
    }
    if(cnt>mxCnt){
                mxCnt=cnt;
            }
            cout<<mxCnt<<endl;
    return 0;
}