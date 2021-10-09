#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int median(vector<vector<int>>mat,int r,int c){
        if(c%2){
            int middle=(c/2);
            int sum=0;
            for(int i=0;i<r;i++){
                sum+=mat[i][middle];
            }
            return sum/r;
        }
        else{
            int middle1=c/2;
            int middle2=(c/2)+1;
            int sum=0;
            for(int i=0;i<r;i++){
                sum+=(mat[i][middle1]+mat[i][middle2])/2;
            }
            return sum/r;
        }
    }
};

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    Solution obj;
    cout<<obj.median(mat,r,c)<<endl;
}