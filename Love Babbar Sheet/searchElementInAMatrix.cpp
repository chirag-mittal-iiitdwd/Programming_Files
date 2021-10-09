#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    int matSearch(vector<vector<int>>&mat,int n,int m,int x){
        int largest=mat[n-1][m-1];
        int smallest=mat[0][0];
        if(x>=smallest && x<=largest){
            int answerRow;
            for(int i=0;i<n;i++){
                if(x>=mat[i][0] && x<=mat[i][m-1]){
                    answerRow=i;
                }
            }
            int ans=0;
            for(int i=0;i<m;i++){
                if(x==mat[answerRow][i]){
                    ans=1;
                    return ans;
                }
            }
            return ans;
        }
        else{
            return 0;
        }
    }
};

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    Solution obj;
    cout<<obj.matSearch(arr,n,m,x)<<endl;
}