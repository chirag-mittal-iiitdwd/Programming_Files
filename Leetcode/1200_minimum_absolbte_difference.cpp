#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr){
        int n = arr.size() ;
        sort(arr.begin(),arr.end());
        stack<pair<int,int>> st ;
        for(int i=0;i<n-1;i++){
            if(st.empty()){
                st.push({arr[i],arr[i+1]}) ;
                continue ;
            }
            int diff = arr[i+1]-arr[i] ;
            int x = st.top().second - st.top().first ;
            if(x<diff){
                continue;
            }
            if(x==diff){
                st.push({arr[i],arr[i+1]}) ; continue ;
            }
            
            while(!st.empty())
                st.pop() ;
            st.push({arr[i],arr[i+1]}) ;
            
        }
        vector<vector<int>> ans ;
        while(!st.empty()){
            ans.push_back({st.top().first,st.top().second}) ;
            st.pop() ;
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        vector<vector<int>>v=obj.minimumAbsDifference(arr);
        for(auto &it:v){
            for(auto &i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}