// map::begin/end  
#include <iostream>  
#include <map>  
  
int main ()  
{  
  std::map<char,int> mymap;  
  //std::map<char,int>::iterator it;  
  
  mymap['z'] = 100;  
  mymap['a'] = 200;  
  mymap['z'] = 300;  
  
  // show content:  
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)  
    std::cout << it->first << " => " << it->second << '\n';  
  system("pause");
  return 0;  
}  