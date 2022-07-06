#include<bits/stdc++.h>
using namespace std;

int recursive(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int curPoints=points[day][task]+recursive(day-1,task,points);
            maxi=max(maxi,curPoints);
        }
    }

    return maxi;
}

int memo(vector<vector<int>>&points,vector<vector<int>>&dp,int last,int day){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,task);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1){
        return dp[day][last];
    }

    int maxi=0;
    for(int task=0;task<3;task++){
        if(last!=task){
            int curPoints=points[day][task]+memo(points,dp,task,day-1);
            maxi=max(maxi,curPoints);
        }
    }

    return dp[day][last]=maxi;
}

int tablutation(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][1],max(points[0][3],points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }

    return dp[n-1][3];
}

int spaceOpt(int n,vector<vector<int>>&points){
    vector<int>dp(4,0);
    dp[0]=max(points[0][1],points[0][2]);
    dp[0]=max(points[0][0],points[0][2]);
    dp[0]=max(points[0][1],points[0][0]);
    dp[0]=max(points[0][1],max(points[0][3],points[0][2]));

    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[day][task]+dp[task]);
                }
            }
        }
        dp=temp;
    }

    return dp[3];
}