/*
    1.  Map prefix sum to a map
    2.  For every key, choose 2 values from all the occurrences of 
        particular prefsum (MC2)
    3. Special Case : for prefsum 0, we have to also include them.
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>cnt;
    int prefSum=0;
    for(int i=0;i<n;i++){
        prefSum+=a[i];
        cnt[prefSum]++;
    }
    int ans=0;
    map<int,int>::iterator it;
    for(it=cnt.begin();it!=cnt.end();it++){
        int c=it->second;
        cout<<c<<endl;
        ans+=(c*(c-1))/2;
        if(it->first==0){
            ans+=it->second;
        }
    }

    cout<<ans<<endl;
}