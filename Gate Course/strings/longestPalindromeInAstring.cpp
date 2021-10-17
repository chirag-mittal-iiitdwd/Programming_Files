#include <bits\stdc++.h>
using namespace std;

string longestPalin (string S) {
        string res="";
        int n=S.size();
        cout<<"N : "<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<endl<<"i : "<<i<<endl;
            string ans="";
            int j=i;
            cout<<"j : "<<j<<endl;
            while(j<n&&S[i]==S[j]){
                ans.push_back(S[j]);
                j++;
            }
            cout<<"ans after first loop : "<<ans<<endl;
            int k=i-1;
            cout<<"k : "<<k<<endl;
            cout<<"j : "<<j<<endl;
            while(k>=0&&S[k]==S[j]){
                ans=S[k]+ans+S[j];
                k--;
                j++;
            }
            cout<<"ans after second loop : "<<ans<<endl;
            if(ans.size()>res.size()){
                res=ans;
                cout<<"res : "<<res<<endl;
            }
        }
        return res;
    }

    int main(){
        string str;
        cin>>str;
        cout<<longestPalin(str)<<endl;
    }