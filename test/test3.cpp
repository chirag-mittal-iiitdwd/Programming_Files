#include <iostream>
#include <climits>
using namespace std;

class MinHeap
{
    int *harr;
    int capacity;
    int heapSize = 0;

    public:
        int insertElement(int val);
        int deleteElement(int val);
        int swap(int *a, int *b){ 
            int *temp = a;
            a = b;
            b = temp;
        }
        int parent(int a);
        int leftChild(int a);
        int rightChild(int a);
        MinHeap(int cap)
        {
            capacity = cap;
            int harr1[cap];
            // harr = new int[cap];
        }
};

int MinHeap::insertElement(int val){
    if(heapSize == capacity){
        cout<<"/nOverload/n";
        return INT_MAX;
    }

    heapSize++;
    int i = heapSize - 1;
    harr[i] = val;
};