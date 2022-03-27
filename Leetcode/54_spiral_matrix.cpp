#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>ans;

        int startRow=0,endRow=n-1,startCol=0,endCol=m-1,totalCnt=n*m,cnt=0;
        while(startCol<=endCol && startRow<=endRow){
            for(int i=startCol;i<=endCol;i++){
                ans.push_back(matrix[startRow][i]);
                cnt++;
                if(cnt==totalCnt){
                    break;
                }
            }
            startRow++;
            if(cnt==totalCnt){
                break;
            }
            
            for(int i=startRow;i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
                if(cnt==totalCnt){
                    break;
                }
            }
            if(cnt==totalCnt){
                break;
            }
            endCol--;
            
            for(int i=endCol;i>=startCol;i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
                if(cnt==totalCnt){
                    break;
                }
            }
            if(cnt==totalCnt){
                break;
            }
            endRow--;

            for(int i=endRow;i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
                cnt++;
                if(cnt==totalCnt){
                    break;
                }
            }
            startCol++;
            if(cnt==totalCnt){
                break;
            }
        }
        return ans;
    }
};