#include<bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>>matrix,int endRow,int endCol){
    vector<int>ans;
	int i, startRow = 0, startCol = 0;
	while (startRow < endRow && startCol < endCol) {
		for (i = startCol; i < endCol; ++i) {
			ans.push_back(matrix[startRow][i]);
		}
		startRow++;
		for (i = startRow; i < endRow; ++i) {
			ans.push_back(matrix[i][endCol - 1]);
		}
		endCol--;
		if (startRow < endRow) {
			for (i = endCol - 1; i >= startCol; --i) {
				ans.push_back(matrix[endRow - 1][i]);
			}
			endRow--;
		}
		if (startCol < endCol) {
			for (i = endRow - 1; i >= startRow; --i) {
				ans.push_back(matrix[i][startCol]);
			}
			startCol++;
		}
	}
    return ans;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>matrix(r);
    for(int i=0;i<r;i++){
        matrix[i].assign(c,0);
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    for(auto x:spirallyTraverse(matrix,r,c)){
        cout<<x<<" ";
    }
    cout<<endl;
}