#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int N = 1e5 + 1;
    vector<int>adj[N];
    bool visited[N];
    
    void DFS(string& s, int i, vector<char>&  chars, vector<int>& indices){
        chars.push_back(s[i]);
        indices.push_back(i);
        
        visited[i] = true;
        for(int neighbour : adj[i]){
            if(!visited[neighbour])
                DFS(s, neighbour, chars, indices);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto pair : pairs){
            int src = pair[0];
            int dst = pair[1];
            
            adj[src].push_back(dst);           
            adj[dst].push_back(src);
        }
        
        for(int i=0; i<s.size(); i++){
            if(!visited[i]){
                vector<char>chars;
                vector<int>indices;
                
                DFS(s, i, chars, indices);
                
                sort(chars.begin(), chars.end());
                sort(indices.begin(), indices.end());
                
                for(int j = 0; j< chars.size(); j++)
                    s[indices[j]] = chars[j];
            }
        }
        return s;
    }
};