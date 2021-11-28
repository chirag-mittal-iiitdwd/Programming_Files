#include <bits/stdc++.h>
using namespace std;
class Solution{
	int t[100][100];
	int mainLogic(int* p, int i, int j){
		if (i == j){
			return 0;
		}
		if (t[i][j] != -1){
			return t[i][j];
		}
		t[i][j] = INT_MAX;
		for (int k = i; k < j; k++){
			t[i][j] = min(t[i][j], mainLogic(p, i, k)+ mainLogic(p, k + 1, j)+ p[i - 1] * p[k] * p[j]);
		}
		return t[i][j];
	}
	public:
	int matrixChainMultiplication(int* p, int n){
		memset(t, -1, sizeof t);
		int i = 1, j = n - 1;
		return mainLogic(p, i, j);
	}
};

int main(){
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	Solution obj;
	cout << "Minimum number of multiplications is "<< obj.matrixChainMultiplication(arr, n)<<endl;
}