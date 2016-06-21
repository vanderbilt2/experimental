aaabbbccc

abababccc
abcabcabc

aaabbbccc

result: 
storage: substring1: abc                      
         rest: aabbcc
         (from rest)->
         substring2: abc
         rest2: abc
         ...
         rest doesn't yelt 'rest_i'
         
         s1: abc s2: cba s3: cba
         
         
 a 2 b 4  ...... (20) .. c 10 
N = min(2,4); 
ababbb ccc         
abab bb ccc  
       
bb ccc         
acbcacbab

include <vector>
using namespace std;

bool rearrange(char *workstring, int N)
{
  bool ret = false;
  vector<int> count;
  map<char, int> uniques;
  for(int i=0; i<N; ++i)
  {
    if(uniques.find(workstring[i]))
    {
      
    }
  }
  
  return ret;
}



