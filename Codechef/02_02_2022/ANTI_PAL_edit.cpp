#include<bits/stdc++.h>
/*
    Soring
    Stack
    Queue
    Dynamic Programming
    Backtracking
    Linked List
    Sliding Window
    Tree
    Two Pointer
    Binary Search
    Maths
    Graph
    Greedy
    Heaps
    Hashing
*/
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
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
        if(n&1){
            cout<<"NO\n";
            continue;
        }

        vector<int>cnt(26,0);
        for(auto&it:str){
            cnt[it-'a']++;
        }
        int max_cnt=*max_element(cnt.begin(),cnt.end());
        if(max_cnt>(n/2)){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        string ans{""};
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                ans+=string(cnt[i],char(i+'a'));
            }
        }
        reverse(ans.begin(),ans.begin()+(n/2));
        cout<<ans<<endl;
    }
    return 0;
}