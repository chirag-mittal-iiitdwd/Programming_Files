#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& bank) {
        int ans=0;
        set<string>dict;
        for(auto&it:bank){
            dict.insert(it);
        }

        if(dict.count(endWord)==0){
            return -1;
        }
        int cnt=1;
        queue<string>q;
        set<string>visited;
        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string cur=q.front();
                q.pop();
                if(cur==endWord){
                    return cnt;
                }

                int n=cur.size();
                for(int i=0;i<n;i++){
                    for(char j:{'A','C','G','T'}){
                        string x=cur.substr(0,i)+j+cur.substr(i+1);
                        if(dict.count(x)!=0 && visited.count(x)==0){
                            cout<<"exe "<<x<<endl;
                            q.push(x);
                            visited.insert(x);
                            cnt++;
                        }
                    }
                }
            }
            
        }
        return cnt;
    }
};