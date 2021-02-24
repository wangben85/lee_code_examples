#include <string>
#include <string.h>        // used for strlen
#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <list>            // use list
#include <algorithm>       // in order to use for_each
#include <deque>           // use deque
#include <queue>           // use queue and priority_queue
#include <set>             // use set and multiset
#include <map>             // use map
#include <stdlib.h>        // use srand
#include <time.h>          // use time


using namespace std;

// Ben Wang's solution
class Solution
{
public: 
   int lengthofLongestSubstring( string s)
   { 
       int maxLength = 1;
       int count = 1;
       int p;
       int q;

       if ( s.size() == 0)  return 0;
      
       for( int i = 0; i < s.size();)
       {
   repeat:
          if ( count >= maxLength)   maxLength = count;
          count = 1;
          for( int j = i + 1; j < s.size(); j++)
          {
              q = i;
              p = j; 
              while ( q < p)
              {
                if ( s[q] == s[p] )
                {
                   i++;
                   if ( i == s.size() - 1)  goto end;
                   goto repeat;
                }
                else
                {
                  q++;
                }
                if ( q == p)
                {
                  count++;
                  if ( j == s.size() - 1) goto end;
                }
              }
          }
       }
   end:
   return maxLength;
   }
};

int main(int argc, const char *argv[])
{
  int len;
  string testStr;
  cout << "input string is : ";
  cout << endl;
  cin >> testStr ;          // input string from terminal

  Solution testSolution;
  len = testSolution.lengthofLongestSubstring(testStr);
  cout << "the string length = " << len << endl; 
  return 0;
}
