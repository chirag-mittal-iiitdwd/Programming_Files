#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxVol=INT_MIN;
        while(i<j){
            int minHeight=min(height[i],height[j]);
            int vol=(j-i)*minHeight;
            maxVol=max(vol,maxVol);

            // We move the lowest one ahead or behind because we want maxVol
            // When both height are equal then dosn't matter which way to move
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxVol;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>height(n);
        for(int i=0;i<n;i++){
            cin>>height[i];
        }
        Solution obj;
        cout<<obj.maxArea(height)<<endl;
    }
}