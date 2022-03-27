#include<bits/stdc++.h>
using namespace std;

class Solution {
    void makeRowAndCol0(vector<vector<int>>&matrix,int r,int c,int n,int m){
        for(int i=0;i<n;i++){
            matrix[i][c]=0;
        }
        for(int i=0;i<m;i++){
            matrix[r][i]=0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dup=matrix;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dup[i][j]==0){
                    makeRowAndCol0(matrix,i,j,n,m);
                }
            }
        }
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),lastRow=-1;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    lastRow=i;
                    break;
                }
            }
            if(lastRow!=-1){
                break;
            }
        }
        if(lastRow==-1){
            return;
        }

        
    }
};