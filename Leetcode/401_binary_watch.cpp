#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        
        vector<int>hour={0,1,2,4,8};
        vector<int>minute={0,1,2,4,8,16,32};
        int nh=hour.size(),nm=minute.size();

        for(int i=0;i<nh;i++){
            for(int j=0;i<nm;j++){
                if((i+j)>turnedOn){
                    break;
                }
                if(nm<10){
                    string str=to_string(hour[i])+':0'+to_string(minute[j]);
                    ans.push_back(str);
                }
                else{
                    string str=to_string(hour[i])+':'+to_string(minute[j]);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};