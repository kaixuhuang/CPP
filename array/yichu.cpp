#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,index;
        index = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
                nums[index++] = nums[i];
        }
        return index;

    }

    int removeDuplicates(vector<int>& nums) {
        int i, index;
        index = 0;
        nums[index] = nums[0];
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
                nums[++index] = nums[i + 1];
        }
        return index + 1;


    }
    void moveZeroes(vector<int>& nums) {
        int i, index;
        index = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }
        for (i = index; i < nums.size(); i++)
        {
            nums[i] = 0;
        }

    }

    bool backspaceCompare(string s, string t) {
        int index = 0;
        stack<char> a,b;
        int i;
        for (i = 0; i < s.size();i++ )
        {
            if (s[i] == '#') {
                if (!a.empty())
                    a.pop();
            }
            else
                a.push(s[i]);   

            
        }
        for (i = 0; i < t.size(); i++)
        {
            if (t[i] == '#') {
                if (!b.empty())
                    b.pop();
            }

            else
                b.push(t[i]);

         
        }
        if (a.empty() == true && b.empty() == true)
            return true;
        else if (a.size() != b.size())
            return false;
        while (!a.empty())
        {
            if (a.top() != b.top())
            {
                return false;
                break;
            }
            else
            {
                a.pop();
                b.pop();
            }
           
        }

        return true;
        

    }
};

