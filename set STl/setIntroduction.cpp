/* 
    Sets are of two types 
    1. Ordered Set
        - Contains unique elements
        - implemented using balanced BST
        - Elements are in sorted order
        - Random access is not possible, ie you cannot
          get i'th element in O(1)/O(log N)
        -----> Code for insertion and print
            set<int> s;
            s.insert(1);
            s.insert(2);
            s.insert(2);
            s.insert(3);

            for(auto i:s){          Output
                cout<<i<<" ";       1 2 3
            }                       1 2 3
            cout<<"\n";
            for(auto i=s.begin();i!=s.end();i++){
                cout<<*i<<" ";
            }
            cout<<"\n";
            ----> Reverse printing
            for(auto i=s.rbegin();i!=s.rend();i++){
                cout<<*i<<" ";
            }
            cout<<"\n";
        - Present in #include<set> 

        -----> If we use set<int, grater<int>>  s;
            than s set would be sorted in descending order

    2. Unoredred Set
        -Contains unique elements
        -Implemented using hashing
        -Elements are not in sorted order
        -Random access is not possible, i.e you cannot
         get i'th element in O(1)
        -Present in #include<unordered_set> header file

        Everything is similar its just that when we print 
        the elements they are not in any order
        
        -----> Time Complexities
        -Insertion : O(1) in avg case, O(N) in worst case
        -Deletion : O(1) in avg case, O(N) in worst case
        -Lower/Upper_Bound: NA

*/

/* 
    Time Complexities
    - Insertion : O(Log N)
    - Deletion : O(Log N)
    - Lower/Upper_bound : O(Log N)
*/

#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for (auto i : s){
        cout << i << " ";
    }
    cout << "\n";
    cout << s.size() << "\n";
    
    return 0;
}