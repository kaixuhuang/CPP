#include<iostream>
#include<vector>
#include<set>
#include<algorithm> 
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, j, min,sum,len;
        min = 0,j=0,sum=0;
        for (i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                len = i - j + 1;
                if (min == 0)
                    min = len;
                else if (len < min)
                    min = len;
                sum -= nums[j++];
            }
        }
        return min;

    }
    int totalFruit(vector<int>& fruits) {
        int i,j,sum,max;
        int lan1, lan2;
        lan1 = -1, lan2 = -1;
        j = 0, sum = 0,max=0;
        if (fruits.size() == 1)
            return 1;
        else if (fruits.size() == 2)
            return 2;
        for (i = 0; i < fruits.size(); i++)
        {
            if ((lan1 == fruits[i] || lan2 == fruits[i]))
            {
            if (i == fruits.size() - 1)

                if (sum + 1 > max)
                    max = ++sum;
            sum++;
            }
            else if (lan1 == -1 || lan2 == -1)
            {
                if (lan1 == -1 && lan2 != fruits[i])
                    lan1 = fruits[i];
                else if (lan2 == -1 && lan1 != fruits[i])
                    lan2 = fruits[i];
                else if (lan1 == fruits[i]&& lan2 == -1)
                    j++;
                sum++;
            }

            else if (lan1 != fruits[i] && lan2 != fruits[i])
            {
                if (sum > max)
                    max = sum;
                lan1 = -1, lan2 = -1;
                i = j++;
                sum = 0;
            }
            else
                sum++;

         
                
            
           
        }

        return max;
    }


};
