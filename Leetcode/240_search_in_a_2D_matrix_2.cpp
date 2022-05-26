#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),r=0,c=matrix[0].size()-1;

        while(r<n && c>=0){
            if(matrix[r][c]==target){
                return true;
            }

            if(matrix[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(),r=matrix.size()-1,c=0;

        while(r>=0 && c<m){
            if(matrix[r][c]==target){
                return true;
            }

            if(matrix[r][c]>target){
                r--;
            }
            else{
                c++;
            }
        }

        return false;
    }
};