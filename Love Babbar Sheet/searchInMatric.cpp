#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x){
	    int smallest=mat[0][0],largest=mat[n-1][m-1];
        if(x<smallest || x>largest){
            return 0;
        }
        int i=0,j=n-1;
        
	}
};

int main(){
    Solution obj;
    int r,c,t;
    cin>>r>>c>>t;
    vector<vector<int>>matrix(r);
    for(int i=0;i<r;i++){
        matrix[i].assign(c,0);
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<obj.searchMatrix(matrix,t);
}