/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
#include <stdio.h> 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//test vector
vector<int> numTest = {2, 7, 11, 15, 20};
vector<int> result = {0, 0};
int target = 31;
string targetStr = "The target is";
string resultStr = "The result is";
string resultStrMain = "In main the result is";

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    cout << targetStr.c_str() << endl;
    cout << target << endl;
    for( int i = 0; i < nums.size() - 1; i++ )
       for ( int j = i + 1; j < nums.size(); j++ )
          if (( nums[i] + nums[j]) == target)
          {
             cout << resultStr.c_str() << endl;
             cout << '(' << i << ',' << j << ')' << endl;
             return {i, j};
             break;
          }
    return {0,0};
  }
};

int main(void) 
{
    Solution t1 = Solution();
    result = t1.twoSum(numTest, target);
    cout << resultStrMain.c_str() << endl;
    cout << '(' <<result[0] << ',' << result[1] << ')' << endl;
    return 0;
}