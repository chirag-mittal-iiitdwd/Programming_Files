#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;

        for(int i=1;i<=min(m,n);i++){
            for(int j=0;j<=n-i;j++){
                for(int k=0;k<=m-i;k++){
                    if(matrix[j][k]==1){
                        for(int x=j;x<j+i;x++){
                            for(int y=k;y<k+i;y++){
                                
                            }
                        }
                    }
                }
            }
        }
    }
};