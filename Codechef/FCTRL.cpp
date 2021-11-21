// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll fiveCnt=0;
//         for(ll i=5;i<=n;i*=5){
//             fiveCnt+=(n/i);
//         }
//         cout<<fiveCnt<<endl;
//     }
//     return 0;
// }

#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=5;i<=n;i*=5){
            ans+=(n/i);
        }
        printf("%d\n",ans);
    }
}