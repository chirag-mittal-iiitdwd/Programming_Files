#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>q(target.begin(),target.end());
        long sum=0;
        for(auto&it:target){
            sum+=it;
        }

        while(true){
            int cur=q.top();
            q.pop();
            sum-=cur;
            
            if(cur==1 || sum==1){
                return true;
            }
            if(cur<sum || sum==0 || cur%sum==0){
                return false;
            }

            cur%=sum;
            sum+=cur;
            q.push(cur);
        }

        return false;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;
        
        for(int item : target){
            pq.push((long long)item);
            sum += item;
        }
        
        while(pq.top() != 1){
            long long top = pq.top(); pq.pop();
            sum = sum - top;
            if(sum <= 0 || sum >= top){ 
                return false;
            }
            
            top = top % sum;
            sum += top;
            pq.push(top);
        }
        
        return true;    
    }
};