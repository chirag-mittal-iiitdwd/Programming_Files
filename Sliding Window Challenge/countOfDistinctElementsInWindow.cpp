
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution{
    public:
    vector<int> countDistinct(int arr[],int n,int k){
        vector<int>ans;
        unordered_map<int,int>m;
        int distCnt=0;
        for(int i=0;i<k;i++){
            if(m[arr[i]]==0){
                distCnt++;
            }
            m[arr[i]]++;
        }
        ans.push_back(distCnt);
        for(int i=1;i<n-k+1;i++){
            if(m[arr[i-1]]==1){
                distCnt--;
            }
            m[arr[i-1]]--;
            m[arr[i+k-1]]++;
            if(m[arr[i+k-1]]==1){
                distCnt++;
            }
            ans.push_back(distCnt);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    for(auto it:obj.countDistinct(arr,n,k)){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}