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
        set<int>st;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int x=i^j;
                if(x<=n){
                    st.insert(x);
                }
            }
        }
        cout<<st.size()<<endl;
        cout<<endl;
    }
    return 0;
}