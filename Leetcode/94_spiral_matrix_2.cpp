#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>spiral(n,vector<int>(n));

        int startRow=0,endRow=n-1,startCol=0,endCol=n-1,ele=n*n;
        int cnt=1;
        while(cnt<=ele && startRow<=endRow && startCol<=endCol){
            for(int i=startCol;i<=endCol;i++){
                spiral[startRow][i]=cnt;
                cnt++;
                // if(cnt>ele){
                //     break;
                // }
            }
            startRow++;
            // if(cnt>ele){
            //     break;
            // }

            for(int i=startRow;i<=endRow;i++){
                spiral[i][endCol]=cnt;
                cnt++;
                // if(cnt>ele){
                //     break;
                // }
            }
            endCol--;
            // if(cnt>ele){
            //     break;
            // }

            for(int i=endCol;i>=startCol;i--){
                spiral[endRow][i]=cnt;
                cnt++;
                // if(cnt>ele){
                //     break;
                // }
            }
            endRow--;
            // if(cnt>ele){
            //     break;
            // }

            for(int i=endRow;i>=startRow;i--){
                spiral[i][startCol]=cnt;
                cnt++;
                // if(cnt>ele){
                //     break;
                // }
            }
            startCol++;
            // if(cnt>ele){
            //     break;
            // }
        }

        return spiral;
    }
};