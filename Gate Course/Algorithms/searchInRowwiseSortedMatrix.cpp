#include<bits\stdc++.h>
using namespace std;

bool searchInMatrix(vector<vector<int>>mat,int r,int c,int x){
    bool found=false;
    int maxi=mat[r-1][c-1];
    int mini=mat[0][0];

    if(x>=mini && x<=maxi){
        int targetRow=-1;
        for(int i=0;i<r;i++){
            if(x>=mat[i][0] && x<=mat[i][c-1]){
                targetRow=i;
            }
        }
        for(int i=0;i<c;i++){
            if(mat[targetRow][i]==x){
                found=true;
                return found;
            }
        }
    }
    else{
        return found;
    }
}

bool searchInMatrix2(vector<vector<int>>mat,int r,int c,int x){
    bool found=false;
    int startRow=0,startCol=c-1;
    while(startRow<r && startCol>=0){
        if(mat[startRow][startCol]==x){
            found=true;
            return found;
        }
        else{
            if(mat[startRow][startCol]>x){
                startCol--;
            }
            else{
                startRow++;
            }
        }
    }
    return found;
}

int main(){
    int r,c,x;
    cin>>r>>c>>x;
    vector<vector<int>>mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<searchInMatrix(mat,r,c,x)<<endl;
    cout<<searchInMatrix2(mat,r,c,x)<<endl;
}