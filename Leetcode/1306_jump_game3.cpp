#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        queue<int> q;
        q.push(cur);
        while(q.size()>0) {
            cur = q.front(); 
            q.pop();
            if(A[cur] == 0){
                return true;
            }
            if(A[cur] < 0){
                continue;
            }
            if(cur + A[cur] < A.size()){
                q.push(cur + A[cur]);
            }
            if(cur - A[cur] >= 0){      
                q.push(cur - A[cur]);
            }
            A[cur] *= -1;
        }
        return false;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,start;
        cin>>n>>start;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution obj;
        cout<<obj.canReach(arr,start)<<endl;
    }
}