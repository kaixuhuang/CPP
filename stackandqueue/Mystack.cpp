#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);

    }

    int pop() {
        int result;
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
          
        }
        result = out.top();
        out.pop();
        return result;

    }

    int peek() {
        int peek = this->pop();
       out.push(peek);
        return peek;

    }

    bool empty() {
        if (in.empty() && out.empty())
            return true;
        else
            return false;
    }
};
//int main() {
//    MyQueue myQueue ;
//    myQueue.push(1);
//    myQueue.push(2);
//    myQueue.peek();
//    myQueue.pop();
//    myQueue.empty();
//
//
//
//
//    return 0;
//}