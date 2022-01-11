
#include<bits/stdc++.h>
using namespace std;

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('d');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  if(itlow==itup){
      cout<<"yes"<<endl;
  }
  else{
      cout<<"no"<<endl;
  }
  cout<<itlow->first<<endl;
  cout<<itup->first<<endl;
  return 0;
}