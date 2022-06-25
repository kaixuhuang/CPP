#include<iostream>
#include<vector>
#include <algorithm>

#include <iterator>
#include <sstream>
using namespace std;
class Solution {
public:
    //344
    void reverseString(vector<char>& s) {
        char tmp;
        int left, right;
        if (s.size() > 1)
        {
            left = 0;
            right = s.size() - 1;
            while (left < right)
            {
                tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
      

    }
    ////541
    //string reverseStr(string s, int k) {
    //    for (int i = 0; i < s.size(); i+=2*k)
    //    {
    //        if (i + k < s.size())
    //        {
    //            reverse(s.begin() + i, s.begin() + i + k);
    //            continue;
    //        }
    //        reverse(s.begin() + i, s.end());

    //    }
    //    return s;

    //}
    //剑指 Offer 05. 替换空格
    string replaceSpace(string s) {
        vector<char> tmp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                tmp.emplace_back(s[i]);
            else
            {
                tmp.emplace_back('%');
                tmp.emplace_back('2');
                tmp.emplace_back('0');
                i++;

            }
        }

        stringstream ss;
        copy(tmp.begin(), tmp.end(), ostream_iterator<int>(ss, ""));
        string A;
        A = ss.str();
        return s;


    }
    void removeExtraSpaces(string &s)
    {
        int fast, slow;
        slow = 0;
        for (fast = 0; fast < s.size() - 1; fast++)
            if (s[fast] != ' ')
                break;

        for (; fast < s.size(); fast++)
        {
            if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ')
                continue;
            else
                s[slow++]=s[fast];
        }
        slow--;
        while (slow > 0 && s[slow] == ' ')
        {
            slow--;
        }
        s.resize(slow+1);
    }
    void reverse(string& s, int start, int end) { //翻转，区间写法：闭区间 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }

    }

    //剑指 Offer 58 - II. 左旋转字符串
    string reverseLeftWords(string s, int n) {
        int index, i;
        string x = s.substr(0, n);
        for (index = 0; index + n < s.size(); index++)
        {
            s[index] = s[index + n];
        }
        for (i = 0; index < s.size(); index++)
        {
            s[index] = x[i++];
        }
        return s;
    }
    //28. 实现 strStr()
    int strStr(string haystack, string needle) {
        int pos = 0;
        if (needle.size() < 1)
            return pos;
        int len1, len2;
        int left, right;
        len1 = haystack.size();
        len2 = needle.size();
        for (left = 0; left + len2 <= len1; left++)
        {
            string x = haystack.substr(left,  len2);
            if (x == needle)
            return left;

        }
        return pos;

            

    }

};
int main() {

    string a = "abc";
    string b = "c";
    int x = 2;
    Solution A;
    //A.removeExtraSpaces(a);

    cout << A.strStr(a, b);


}