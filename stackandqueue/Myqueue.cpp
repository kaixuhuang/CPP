#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> a;
    MyStack() {

    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        int len = a.size();
        while (len != 1)
        {
            a.push(a.front());
            a.pop();
            len--;
        }
        int result = a.front();
        a.pop();
        return result;
    }

    int top() {
        int result = a.back();
        return result;
    }

    bool empty() {
        return a.empty();
    }
};
