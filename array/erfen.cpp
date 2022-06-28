#include<iostream>

#include<vector>
using namespace std;
class Solution {
public:
    //二分
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > target)
            {
                middle -= 1;
                right = middle;
            }
            else if (nums[middle] < target)
            {
                middle+=1;
                left = middle;


            }
            else
            return middle;
        }
        return -1;

    }
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int middle=-1;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > target)
            {
                middle -= 1;
                right = middle;
            }
            else if (nums[middle] < target)
            {
                middle += 1;
                left = middle;
            }
            else
                return middle;
        }
        return left;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> aa;
        int left = 0;
        int right = nums.size() - 1;
        int middle1 , middle2,middle;
        middle1 = -1, middle2 = -1;
        if (nums.size() == NULL || (target != 0 && target == NULL))
        {
            aa.push_back(middle1);
            aa.push_back(middle2);
            return aa;
        }
        else {

            while (left <= right)
            {
                middle = (left + right) / 2;
                if (nums[middle] >= target)//左边界
                {
                    if (nums[middle] == target)
                        middle1 = middle;
                    middle -= 1;
                    right = middle;
 
                }
                else if (nums[middle] < target)
                {
                    middle += 1;
                    left = middle;
                        
                }
            }
             left = 0;
             right = nums.size() - 1;
            while (left <= right)//右边界
            {
                middle = (left + right) / 2;
                
               if (nums[middle] <= target)
                {
                    if (nums[middle] == target)
                        middle2 = middle;
                    middle += 1;
                    left = middle;
                    

                }
                else if (nums[middle] > target)
                {
                    middle -= 1;
                    right = middle;
                }
            }
            if (middle1 <= middle2)
            {
                aa.push_back(middle1);
                aa.push_back(middle2);
            }
            else
            {
                aa.push_back(middle2);
                aa.push_back(middle1);
            }

            return aa;
        }
    }
   
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        int min = 0;
        int max = x;
        int mid;
        while (max-min>1)
        {
            mid = (max + min) / 2;
            if (x / mid < mid)
                max = mid;
            else
                min = mid;


        }
        return min;
    }
    bool isPerfectSquare(int num) {

        if (num == 1)
            return true;
        int min = 0;
        int max = num;
        int mid;
        while (max - min > 1)
        {
            mid = (max + min) / 2;
            if (num / mid < mid)
                max = mid;
            else
                min = mid;


        }
        if ((num - min * min) == 0)
            return true;
        else
            return false;



    }


};

