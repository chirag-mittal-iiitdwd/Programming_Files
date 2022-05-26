#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int minX=0,minY=0;

        if(ax1<0){
            minX=min(minX,ax1);
        }
        if(bx1<0){
            minX=min(minX,bx1);
        }

        if(ay1<0){
            minX=min(minX,ay1);
        }
        if(by1<0){
            minX=min(minX,by1);
        }

        ax1+=abs(minX);
        bx1+=abs(minX);
        ay1+=abs(minY);
        by1+=abs(minY);

        int length1=ax2-ax1;
        int length2=bx2-bx1;
        int height1=ay2-ay1;
        int height2=by2-by1;
        
        cout<<length1<<" "<<height1<<" "<<length2<<" "<<height2<<endl;
        int area=(length1*height1)+(length2*height2);

        if(ax1<=bx1){

        }

        return area;
    }
};
                //   1             2             3             4
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F); 
    if (A >= G || C <= E || D <= F || B >= H)
        return s1 + s2; 
    return s1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + s2;
}