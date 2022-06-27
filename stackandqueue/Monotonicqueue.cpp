#include<iostream>
#include<deque>
#include<vector>
using namespace std;
//单调队列
class Mqueue {
public:
    deque<int> que;

    
    void pop(int value){
        if (!que.empty() && value == que.front())
        {
            que.pop_front();
        }

    }
    void push(int value) {
        while(!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.emplace_back(value);

    }
    int front() {
        return que.front();


    }



};



class Solution {
public:
    //239滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Mqueue maxque;
        vector<int> max;
        int i, j;
        for (i = 0; i < k; i++)
            maxque.push(nums[i]);
        max.emplace_back(maxque.front());
        for (i = k; i < nums.size(); i++)
        {
            maxque.pop(nums[i - k]);
            maxque.push(nums[i]);
            max.emplace_back(maxque.front());
        }
        return max;
    }
};
int main() {
    vector<int> nums = { 1,3,1,2,0,5 };
    int k = 3;
    Solution A;
    vector<int> max = A.maxSlidingWindow(nums, k);
    for (auto x : max)
    {
        cout << x << " ";
    }


    return 0;
}