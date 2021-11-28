#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>kmp_stringMaching(string str,string srh){
        int n=str.length();
        int x=srh.length();
        vector<int>ans;
        if(n<x){
            return ans;
        }
        for(int i=0;i<n;i++){
            if(str[i]==srh[0]){
                ans.push_back(i);
                for(int j=0;j<x;j++){
                    if(str[i+j]!=srh[j]){
                        ans.pop_back();
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    string str,srh;
    cout<<"Enter The String in which you want to search : ";
    cin>>str;
    cout<<"Enter the string which you want to search : ";
    cin>>srh;
    Solution obj;
    vector<int>ans=obj.kmp_stringMaching(str,srh);
    if(ans.size()==0){
        cout<<"String not found at any index\n";
    }
    else{
        cout<<"String found at "<<ans.size()<<" places\n";
        for(auto &it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}