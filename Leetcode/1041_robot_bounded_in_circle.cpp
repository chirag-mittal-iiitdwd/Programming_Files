#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string str) {
        int n=str.length();
        int dirx=0,diry=1;
        int x=0,y=0;
        for(auto &it:str){
            if(it=='R'){
                int temp=dirx;
                dirx=diry;
                diry=-temp;
            }
            else if(it=='L'){
                int temp=dirx;
                dirx=-diry;
                diry=temp;
            }
            else{
                x+=dirx;
                y+=diry;
            }
        }
        if((x==0 && y==0)||(dirx!=0 || diry!=1)){
            return true;
        }
        else{
            return false;
        }
    }
};