#include <iostream>
using namespace std;
int shellSort(int arr[], int n){
	for (int gap = n/2; gap > 0; gap /= 2){
		for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;		
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n){
	for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shellSort(arr,n);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
