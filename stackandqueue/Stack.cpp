#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include <string>
#include<deque>
using namespace std;
class Solution {
public:
    //1047
    string removeDuplicates(string s) {
        if (s.size() == 0)
            return s;
        stack<char> x;
        x.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (x.empty() || x.top() != s[i])
                x.push(s[i]);
            else
                x.pop();

        }
        string result = "";
        while (!x.empty())
        {
            result += x.top();
            x.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
    //150
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if (tokens[i] == "+")
                    stk.push(num1 + num2);
                else if (tokens[i] == "-")
                    stk.push(num1 - num2);
                else if (tokens[i] == "*")
                    stk.push(num1 * num2);
                else if (tokens[i] == "/")
                    stk.push(num1 / num2);

            }
            else
                stk.push(stoi(tokens[i]));

        }
        return stk.top();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    }
};
//int main() {
//    /*string a = "abbaca";*/
//    vector<int> a = { 1,3,-1,-3,5,3,6,7 };
//    int b = 3;
//    Solution A;
//    vector<int> c = A.maxSlidingWindow(a, b);
//    for (auto x : c)
//        cout << x << " ";
//
//    
//    return 0;
//}