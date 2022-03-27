#include<bits/stdc++.h>
using namespace std;

class Solution {
    static const bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first<b.first){
            return true;
        }
        else if(a.first==b.first){
            if(b.second>a.second){
                return true;
            }
            return false;
        }
        return false;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>q;
        int n=mat.size(),m=mat[0].size();

        for(int i=0;i<n;i++){
            int ones=0;
            for(auto&it:mat[i]){
                if(it==0){
                    break;
                }
                ones++;
            }
            q.push_back({ones,i});
        }
        
        sort(q.begin(),q.end(),comp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(q[i].second);
        }
        return ans;
    }
};

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements>q;
        int n=mat.size(),m=mat[0].size();

        for(int i=0;i<n;i++){
            int ones=0;
            for(auto&it:mat[i]){
                if(it==0){
                    break;
                }
                ones++;
            }
            q.push({ones,i});
            if(q.size()>k){
                q.pop();
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};

class Solution {
    int calculateSoldierCount(vector<int>& v) {
        int l=0; int h=v.size()-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(v[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;

        for(int i=0;i<mat.size();++i){
            max_heap.push({calculateSoldierCount(mat[i]),i});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        vector<int>ans;
        while(max_heap.size()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
		
        reverse(ans.begin(), ans.end());
        return ans;
    }
};