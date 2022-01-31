//Gauss Elimination
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    cout<<"\nEnter the no. of equations\n";        
    cin>>n;
    float a[n][n+1],x[n];

    cout<<"\nEnter the elements of the augmented-matrix row-wise:\n";
    for (i=0;i<n;i++){
        for (j=0;j<=n;j++){    
            cin>>a[i][j];
        }
    }

    for (i=0;i<n;i++){
        for (k=i+1;k<n;k++){
            // If pivot element is smaller than element below it than we have to swap the rows
            if (abs(a[i][i])<abs(a[k][i])){
                for (j=0;j<=n;j++){
                    swap(a[i][j],a[k][j]);
                }
            }
        }
    }

    // cout<<"\nThe matrix after Pivotisation is:\n";
    // for (i=0;i<n;i++){
    //     for (j=0;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for (i=0;i<n-1;i++){
        for (k=i+1;k<n;k++){
            // taking the element below pivot element and finding the cofficient to be multiplied for row opeartions
            double t=a[k][i]/a[i][i];
            // Elementry row operation
            for (j=0;j<=n;j++){
                a[k][j]=a[k][j]-t*a[i][j];
            }
        }
    }
     
    cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i=0;i<n;i++){
        for (j=0;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    for (i=n-1;i>=0;i--){
        x[i]=a[i][n];
        // cout<<x[i]<<" ";
        for (j=i+1;j<n;j++){
            if (j!=i){
                x[i]=x[i]-a[i][j]*x[j];
            }
        }
        x[i]=x[i]/a[i][i];
    }

    cout<<"\nThe values of the variables are as follows:\n";
    for (i=0;i<n;i++){
        cout<<x[i]<<endl;
    }  
    return 0;
}