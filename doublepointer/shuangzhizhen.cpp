#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //977 
    //vector<int> sortedSquares(vector<int>& nums) {
    //    int left,right;
    //    int n = nums.size();
    //    vector<int> sqrt;
    //    left = -1;
    //    for (int i = 0; i < n; ++i)
    //    {
    //        if (nums[i] < 0) {
    //           left = i;
    //        }
    //        else {
    //            break;
    //        }

    //    }
    //    right = left + 1;
    //    while (left > -1 || right < n)
    //    {

    //        if (left < 0)
    //        {
    //            sqrt.emplace_back(s[right] * s[right]);
    //            right ++ ;
    //        }
    //        else if (right == n)
    //        {
    //            sqrt.emplace_back(s[left] * s[left]);
    //            left--;
    //        }
    //        else if (s[left] * s[left] < s[right] * s[right])
    //        {
    //            sqrt.emplace_back(s[left] * s[left]);
    //            left--;
    //        }
    //        else
    //        {
    //            sqrt.emplace_back(s[right] * s[right]);
    //            right++;
    //        }



    //    }


    //   
    //    return sqrt;
    //}
};