#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     bool findPath(int x,int y,int i,string word,int n,int m,vector<vector<char>>& board,int prevX,int prevY){
//         if(i==word.size()){
//             return true;
//         }

//         int ans=false;
//         if(x+1<n && word[i]==board[x+1][y] && (x+1)!=prevX && y!=prevY){
//             if(findPath(x+1,y,i+1,word,n,m,board,x,y)){
//                 return true;
//             }
//         }

//         if(x-1>=0 && word[i]==board[x-1][y] && (x-1)!=prevX && y!=prevY){
//             if(findPath(x-1,y,i+1,word,n,m,board,x,y)){
//                 return true;
//             }
//         }

//         if(y-1>=0 && word[i]==board[x][y-1] && x!=prevX && y-1!=prevY){
//             if(findPath(x,y-1,i+1,word,n,m,board,x,y)){
//                 return true;
//             }
//         }

//         if(y+1<m && word[i]==board[x][y+1] && x!=prevX && y+1!=prevY){
//             if(findPath(x,y+1,i+1,word,n,m,board,x,y)){
//                 return true;
//             }
//         }

//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<pair<int,int>>start;
//         int n=board.size(),m=board[0].size();

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(board[i][j]==word[0]){
//                     start.push_back({i,j});
//                 }
//             }
//         }

//         if(start.size()>0){
//             for(int i=0;i<start.size();i++){
//                 cout<<start[i].first<<" "<<start[i].second<<endl;
//                 if(findPath(start[i].first,start[i].second,1,word,n,m,board,0,0)){
//                     return true;
//                 }
//                 return false;
//             }
//         }
//         return false;
//     }
// };


// // #include<bits/stdc++.h>
// // using namespace std;

// class Solution {
//     bool findPath(int x,int y,int i,string word,int n,int m,vector<vector<char>>& board){
//         if(i==word.size()){
//             return true;
//         }

//         int ans=false;
//         if(x+1<n && word[i]==board[x+1][y]){
//             if(i==1){
//                 cout<<"start"<<endl;
//             }
//             cout<<"first : "<<word[i]<<" x : "<<x+1<<" y : "<<y<<endl;
//             if(findPath(x+1,y,i+1,word,n,m,board)){
//                 return true;
//             }
//         }

//         if(x-1>=0 && word[i]==board[x-1][y]){
//             if(i==1){
//                 cout<<"start"<<endl;
//             }
//             cout<<"first : "<<word[i]<<" x : "<<x-1<<" y : "<<y<<endl;
//             if(findPath(x-1,y,i+1,word,n,m,board)){
//                 return true;
//             }
//         }

//         if(y-1>=0 && word[i]==board[x][y-1]){
//             if(i==1){
//                 cout<<"start"<<endl;
//             }
//             cout<<"first : "<<word[i]<<" x : "<<x<<" y : "<<y-1<<endl;
//             if(findPath(x,y-1,i+1,word,n,m,board)){
//                 return true;
//             }
//         }

//         if(y+1<m && word[i]==board[x][y+1]){
//             if(i==1){
//                 cout<<"start"<<endl;
//             }
//             cout<<"first : "<<word[i]<<" x : "<<x<<" y : "<<y+1<<endl;
//             if(findPath(x,y+1,i+1,word,n,m,board)){
//                 return true;
//             }
//         }

//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<pair<int,int>>start;
//         int n=board.size(),m=board[0].size();

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(board[i][j]==word[0]){
//                     start.push_back({i,j});
//                 }
//             }
//         }
        
//         cout<<"start.size : "<<start.size()<<endl;
//         cout<<"word : "<<word<<endl;
//         if(start.size()>0){
//             for(int i=0;i<start.size();i++){
//                 cout<<start[i].first<<" "<<start[i].second<<endl;
//                 if(findPath(start[i].first,start[i].second,1,word,n,m,board)){
//                     return true;
//                 }
                
//             }
//             return false;
//         }
//         return false;
//     }
// };

class Solution {
    bool helper(int i,int j,int idx,vector<vector<char>>&board,string word,int n,int m){
        if(idx==word.size()){
            return true;
        }

        if(i<0 || j<0 || j>=m || i>=n ){
            return false;
        }

        if(board[i][j]==word[idx]){
            char cur=board[i][j];
            board[i][j]='@';
            if(helper(i+1,j,idx+1,board,word,n,m)||helper(i,j+1,idx+1,board,word,n,m)||helper(i-1,j,idx+1,board,word,n,m)||helper(i,j-1,idx+1,board,word,n,m)){
                return true;
            }
            board[i][j]=cur;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && helper(i,j,0,board,word,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};