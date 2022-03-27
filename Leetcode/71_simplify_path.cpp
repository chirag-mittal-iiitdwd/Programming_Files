#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string>st;
        
        int i=0,n=path.length();
        while(i<n){
            if(path[i]=='/'){
                i++;
            }
            else{
                string temp;
                while(i<n && path[i]!='/'){
                    temp+=path[i];
                    i++;
                }
                if(temp=="."){
                    i++;
                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                }
                else{
                    st.push_back(temp);
                }
            }
        }

        string ans;
        if(st.size()!=0){
            ans+='/';
        }
        while(!st.empty()){
            ans+=(st.front()+"/");
            st.pop_front();
        }

        return ans.substr(0,ans.length()-1);
    }
};