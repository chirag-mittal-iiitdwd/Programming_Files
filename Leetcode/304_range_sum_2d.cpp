#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<col2;j++){
                sum+=mat[i][j];
            }
        }
        return sum;
    }
};


class NumMatrix {
public:
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        sum=vector<vector<int>>(n+1,vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
};
