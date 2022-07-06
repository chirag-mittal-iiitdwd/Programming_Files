#include<bits/stdc++.h>
using namespace std;

class Solution {
    int useEitherBrichOrLadder(vector<int>&heights,int bricks,int ladders,int idx,int n){
        if(idx==n-1){
            return n-1;
        }
        int hDiff=heights[idx+1]-heights[idx];
        if(hDiff>0 && ladders==0 && bricks<hDiff){
            return idx;
        }

        int ans=0;
        // for(int i=idx;i<n;i++){
            if(idx+1<n && heights[idx+1]<=heights[idx]){
                ans=max(ans, useEitherBrichOrLadder(heights,bricks,ladders,idx+1,n));
            }
            else if(idx+1<n && heights[idx+1]>heights[idx]){
                if(ladders>0){
                    ans=max(ans,useEitherBrichOrLadder(heights,bricks,ladders-1,idx+1,n));
                }
                int heightDiff=heights[idx+1]-heights[idx];
                if(bricks>=heightDiff){
                    ans=max(ans,useEitherBrichOrLadder(heights,bricks-heightDiff,ladders,idx+1,n));
                }
            }
        // }
        return ans;
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return useEitherBrichOrLadder(heights,bricks,ladders,0,heights.size());
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>q;
        int n=heights.size();

        for(int i=1;i<n;i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                q.push(diff);
                if(q.size()>ladders){
                    bricks-=q.top();
                    q.pop();
                    if(bricks<0){
                        return i;
                    }
                }
            }
        }

        return n-1;
    }
};