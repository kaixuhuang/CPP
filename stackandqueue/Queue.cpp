#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    //对于优先级队列的大小排序的重定义
    struct less {
        bool operator()(pair<int, int>& x, pair<int, int>& y) {
            return x.second > y.second;
        }

};


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int x : nums)
            map[x]++;
        priority_queue< pair<int, int>, vector<pair<int, int>>, less>  pri_que;
        for (unordered_map<int, int>::iterator it, it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }

        }
        vector<int> result(k);
        for (int i = k; i > 0; i--)
        {
            result[i - 1] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
        
    }
};
