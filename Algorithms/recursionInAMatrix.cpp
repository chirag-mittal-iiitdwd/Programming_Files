#include"bits/stdc++.h"
#define N 8
#define M 8
using namespace std;
void floodFill(int myScreen[][N], int x, int y, int currColor, int newColor) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (myScreen[x][y] != currColor) 
        return; 
    if (myScreen[x][y] == newColor) 
        return; 
  
    // Replace the color at cell (x, y) 
    myScreen[x][y] = newColor; 
  
    // Recursively call for north, east, south and west 
    floodFill(myScreen, x+1, y, currColor, newColor); 
    floodFill(myScreen, x-1, y, currColor, newColor); 
    floodFill(myScreen, x, y+1, currColor, newColor); 
    floodFill(myScreen, x, y-1, currColor, newColor); 
} 
void findColor(int myScreen[][N], int x, int y, int newColor) 
{ 
    int currColor = myScreen[x][y]; 
    floodFill(myScreen, x, y, currColor, newColor); 
} 
int main() 
{ 
    int myScreen[M][N] = 
                    {
                      {3, 2, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newColor = 3; 
    findColor(myScreen, x, y, newColor); 
  
    cout << "Updated myScreen : \n"; 
    
    //printing screen
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << myScreen[i][j] << " "; 
        cout << endl; 
    } 
    return 0;
} 