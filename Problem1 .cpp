#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence) 
  {  
    if (sequence.size() == 1)
    {
      return 1;
    }
    int cur = 1;
    
    int last = sequence[1] - sequence[0];
    int lastPos = 1;
    
    for (int i = 2; i < sequence.size(); i++)
    {
      if (sequence[i] - sequence[lastPos] > 0 && last < 0)
      {
        cur++;
        last = sequence[i] - sequence[lastPos];
        lastPos = i;
      }
      else if (sequence[i] - sequence[lastPos] < 0 && last > 0)
      {
        cur++;
        last = sequence[i] - sequence[lastPos];
        lastPos = i;
      }      
      else
      {
        if (last > 0 && sequence[i] > sequence[lastPos])
        {
          last = sequence[i] - sequence[lastPos];
          lastPos = i;
        }
        else if (last < 0 && sequence[i] < sequence[lastPos])
        {
          last = sequence[i] - sequence[lastPos];
          lastPos = i;
        }
      }
    }
    
    return cur+1;
  }
};
 
