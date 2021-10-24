#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// ll main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t;
//     cin>>t;
//     while(t--){
//         ll a,b,c;
//         cin>>a>>b>>c;
//         ll arraySize=a+b+c;
//         ll x=(a+(2*b)+(3*c))/2;
//         ll left=(a+(2*b)+(3*c))-x;
//         ll arr[arraySize];
//         for(ll i=0;i<arraySize;i++){
//             if(a!=0){
//                 arr[i]=1;
//                 a--;
//             }
//             else if(b!=0){
//                 arr[i]=2;
//                 b--;
//             }
//             else{
//                 arr[i]=3;
//                 c--;
//             }
//         }
//         ll halfAns=0;
//         ll i=arraySize-1;
//         ll toget=x;
//         while(halfAns<=x && i>=0){
//             if(toget>=arr[i]){
//                 halfAns+=arr[i];
//                 toget-=arr[i];
//             }
//             i--;
//         }
//         cout<<left-halfAns<<endl;
//     }
//     return 0;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t;
//     cin>>t;
//     while(t--){
//         ll a,b,c;
//         cin>>a>>b>>c;
//         a=a%2;
//         b=b%2;
//         c=c%2;
//         ll totalSong=(a+(2*b)+(3*c));
//         ll halfSong=totalSong/2;
//         ll leftSong=totalSong-halfSong;
//         ll lengthOffirst=0;
//         while(halfSong>0){
//             if(halfSong>=3 && c>0){
//                 lengthOffirst+=3;
//                 c--;
//                 halfSong-=3;
//                 // cout<<"exeif "<<"length : "<<lengthOffirst<<" c : "<<c<<" halfsong : "<<halfSong<<endl;
//             }
//             else if(halfSong>=2 && b>0){
//                 lengthOffirst+=2;
//                 b--;
//                 halfSong-=2;
//                 // cout<<"exeifelse1 "<<"length : "<<lengthOffirst<<" b : "<<b<<" halfsong : "<<halfSong<<endl;
//             }
//             else if(halfSong>=1 && a>0){
//                 lengthOffirst+=1;
//                 a--;
//                 halfSong-=1;
//                 // cout<<"exeifelse2"<<" length : "<<lengthOffirst<<" a : "<<a<<" halfsong : "<<halfSong<<endl;
//             }
//             else{
//                 cout<<"else"<<endl;
//                 break;
//             }
//         }
//         cout<<abs(leftSong-lengthOffirst)<<endl;
//     }
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=(a+(2*b)+(3*c));
        if(sum%2){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}