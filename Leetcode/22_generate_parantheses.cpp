#include<bits/stdc++.h>
using namespace std;

class Solution {
    set<string>ans;
    void helper(int st,int&n,string start){
        if(st==n){
            ans.insert(start);
            return;
        }
        for(int i=0;i<start.length();i++){
            string x=start.substr(0,i)+"()"+start.substr(i);
            helper(st+1,n,x);
        }
    }
    public:
    vector<string> generateParenthesis(int n) {
        if(n==1){
            return {"()"};
        }
        else{
            helper(1,n,"()");
            vector<string>x;
            for(auto &it:ans){
                x.push_back(it);
            }
            return x;
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution obj;
        vector<string>ans=obj.generateParenthesis(n);
        for(auto &it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}