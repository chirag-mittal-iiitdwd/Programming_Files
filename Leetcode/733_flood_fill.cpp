#include<bits/stdc++.h>
using namespace std;

class Solution {
    void fillRow(vector<vector<int>>&image,int targetRow,int col,int fillColor,int oldColor){
        for(int i=0;i<col;i++){
            if(image[targetRow][i]==oldColor){
                image[targetRow][i]=fillColor;
            }
        }
    }

    void fillCol(vector<vector<int>>&image,int targetCol,int row,int fillColor,int oldColor){
        for(int i=0;i<row;i++){
            if(image[i][targetCol]==oldColor){
                image[i][targetCol]=fillColor;
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int targetCol=image[sr][sc],n=image.size(),m=image[0].size();

        for(int i=sr-1;i>=0;i--){
            if(image[i][sc]==targetCol){
                fillRow(image,i,m,newColor,targetCol);
            }
            else{
                break;
            }
        }

        for(int i=sr+1;i<n;i++){
            if(image[i][sc]==targetCol){
                fillRow(image,i,m,newColor,targetCol);
            }
            else{
                break;
            }
        }
        

        for(int i=sc-1;i>=0;i--){
            if(image[sr][i]==targetCol){
                fillCol(image,i,n,newColor,targetCol);
            }
            else{
                break;
            }
        }

        for(int i=sc+1;i<m;i++){
            if(image[sr][i]==targetCol){
                fillCol(image,i,n,newColor,targetCol);
            }
            else{
                break;
            }
        }
        image[sr][sc]=newColor;
        return image;
    }
};