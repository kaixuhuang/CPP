#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    //349
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i;
        set<int> mix;
        vector<int> hash(1000);
        for (i = 0; i < nums1.size(); i++)
        {
            if (hash[nums1[i] ]== 0)
                hash[nums1[i]]++;
        }
        for (i = 0; i < nums2.size(); i++)
        {
            if (hash[nums2[i] ]!= 0)
                mix.emplace(nums2[i]);
        }
        return  vector<int>(mix.begin(), mix.end());
    }
    //350
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i;
        vector<int> mix;
        vector<int> hash(1001);
        for (i = 0; i < nums1.size(); i++)
        {
            
                hash[nums1[i]]++;
        }
        for (i = 0; i < nums2.size(); i++)
        {
            if (hash[nums2[i]] != 0)
            {
                --hash[nums2[i]];

                mix.emplace_back(nums2[i]);
            }
        }
        return mix;
    }
    //202
    int getsum(int a)
    {
        int sum=0;
        while (a)
        {
            sum += (a % 10) * (a % 10);
            a = a / 10;
        }
        return sum;
    }
    bool isHappy(int n) {

        unordered_set<int> a;
        while (true)
        {
            n = getsum(n);
            if (n == 1)
                return true;
            else if (a.find(n) == a.end())
                a.emplace(n);
            else
                return false;
        }

    }
    //454
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=0;
        unordered_map<int, int > hash;
        for (int x : nums1)
            for (int y : nums2)
                hash[x+y]++;

        for(int x:nums3)
            for (int y : nums4)
                if (hash.find((0 - x - y)) != hash.end())
                    n+= hash[0-x-y];
            
        return n;



    }
    //454Éµ±Æ½â·¨ ³¬Ê±
    //int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //    int n = 0;
    //    unordered_map<int, int > hash;
    //    for (int x : nums1)
    //        for (int y : nums2)
    //            for (int z : nums3)
    //                for (int w : nums4)
    //                    if (x + y + z + w == 0)
    //                        n++;
    //           
    //   
    //    return n;
    //}

    //15 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return result;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                    while (left < right&& nums[right] == nums[right +1])
                            right--;
                }
                    
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                    while (left < right && nums[left]== nums[left-1])
                        left++;
                }
                else
                {
                    result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    right--;
                    left++;

                }
            }


           

        }
        return result;

    }


};
int main() {

    vector<int> nums = { -1,0,1,2,-1,4 };
    Solution A;
    A.threeSum(nums);

    /*vector<int> nums2 = {2,2};
    
    A.intersect(nums1, nums2);*/


    return 0;
}