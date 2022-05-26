#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
int tempk;
priority_queue<int,vector<int>,greater<int>()>q;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(q.size()<k){
                q.push(nums[i]);
            }
            else{
                if(nums[i]>q.top()){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        tempk=k;
    }
    
    int add(int val) {
        if(q.size()<tempk){
            q.push(val);
        }
        else{
            if(val>q.top()){
                q.pop();
                q.push(val);
            }
        }
        return q.top();
    }
};


// 4 5 8 2
// 8 5 4 