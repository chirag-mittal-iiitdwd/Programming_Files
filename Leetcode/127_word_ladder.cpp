#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        set<string>dict;
        for(auto&it:wordList){
            dict.insert(it);
        }

        if(dict.count(endWord)==0){
            return 0;
        }
        int cnt=0;
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
                    for(char j='a';j<='z';j++){
                        string x=cur.substr(0,i)+j+cur.substr(i+1);
                        if(dict.count(x)!=0 && visited.count(x)==0){
                            cout<<"exe "<<x<<endl;
                            q.push(x);
                            visited.insert(x);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};