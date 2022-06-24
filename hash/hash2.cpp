#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
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

};
int main() {

    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };
    Solution A;
    A.intersect(nums1, nums2);

    return 0;
}