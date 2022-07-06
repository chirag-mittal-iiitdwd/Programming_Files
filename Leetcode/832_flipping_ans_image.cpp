#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size(),m=image[0].size();
        
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                int leftBit=1-image[i][j];
                int rightBit=1-image[i][k];
                image[i][j]=rightBit;
                image[i][k]=leftBit;
            }
        }

        return image;
    }
};