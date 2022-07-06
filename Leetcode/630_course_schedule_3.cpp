#include<bits/stdc++.h>
using namespace std;

class Solution {
    int takeAndNotTake(vector<vector<int>>&courses,int idx,int n,int time,vector<vector<int>>&dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][time]!=-1){
            return dp[idx][time];
        }
        int curDuration=courses[idx][0],before=courses[idx][1];
        int take=INT_MIN,notTake=INT_MIN;
        if(time+curDuration<=before){
            take=takeAndNotTake(courses,idx+1,n,time+curDuration,dp)+1;
        }
        notTake=takeAndNotTake(courses,idx+1,n,time,dp);
        return dp[idx][time] = max(take,notTake);
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        int n=courses.size(),last=courses[n-1][1];
        vector<vector<int>>dp(n,vector<int>(last,-1));
        return takeAndNotTake(courses,0,courses.size(),0,dp);
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });

        priority_queue<int>q;
        int time=0,n=courses.size();

        for(int i=0;i<n;i++){
            int curDur=courses[i][0],closeDur=courses[i][1];
            if(time+curDur<=closeDur){
                q.push(curDur);
                time+=curDur;
            }
            else if(q.size()>0 && q.top()>curDur){
                time+=(curDur-q.top());
                q.pop();
                q.push(curDur);
            }
        }

        return q.size();
    }
};

int main(){
    vector<vector<int>>courses={{2,5},{2,19},{1,8},{1,3}};
    Solution obj;
    cout<<obj.scheduleCourse(courses);
}