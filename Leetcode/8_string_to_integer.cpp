#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
    void removeSpaces(string&s){
        int n=s.length();
        int i=0;
        for(i=0;i<n;i++){
            if(s[i]!=' '){
                break;
            }
        }
        // cout<<"Apce "<<s<<endl;
        s=s.substr(i,n);
        // cout<<"Apce "<<s<<endl;
    }
    bool isNeg(string&s){
        int n=s.length();
        bool flag=false;
        if(s[0]=='-'){
            s=s.substr(1,n);
            flag=true;
        }
        else if(s[0]=='+'){
            s=s.substr(1,n);
        }
        return flag;
    }
    public:
    int myAtoi(string s) {
        removeSpaces(s);
        bool flag=isNeg(s);
        // cout<<"Apce and Sign "<<s<<endl;
        int n=s.length();
        // cout<<"N : "<<n<<endl;
        string ans{""};
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                // cout<<"IF"<<endl;
                ans.push_back(s[i]);
            }
            else{
                // cout<<"ELSE"<<endl;
                break;
            }
        }
        // cout<<ans<<endl;
        if(ans.length()>0){
            try{
                ll ans1=stoi(ans);
                if(flag){
                    ans1=-ans1;
                }
                return ans1;
            }
            catch(std::out_of_range  &e){
                if(flag){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
        }
        else{
            return 0;
        }
    }
};

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        Solution obj;
        // cout<<"After Input :"<<str<<endl;
        cout<<obj.myAtoi(str)<<endl;
    }
}