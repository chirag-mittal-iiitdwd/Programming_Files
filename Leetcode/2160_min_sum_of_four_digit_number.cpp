#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        priority_queue<int,vector<int>,greater<int>>q;

        while(num>0){
            int rem=num%10;
            q.push(rem);
            num/=10;
        }

        int i=0,ans=0;
        while(!q.empty()){
            if(i>1){
                ans+=q.top()*10;
            }
            else{
                ans+=q.top();
            }
            q.pop();
            i++;
        }
        return ans;
    }
};