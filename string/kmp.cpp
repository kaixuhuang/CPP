#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    vector<int> getNext(string s){
        int len = static_cast<int> (s.size());
        vector<int> next(len,0);
        int i;
        int j = 0;
        for (i = 1; i < s.length(); i++)
            {
            while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;


    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int len1, len2;
        len1 = haystack.size();
        len2 = needle.size();
        int i, j;
        vector<int> next;
        next = getNext(needle);
        j = 0;

        for (i = 0; i < len1; i++)
        {
            cout << haystack[i] << " " << needle[j] << endl;

            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }


        }
        return -1;
    
    
    
    }

    //28

        bool repeatedSubstringPattern(string s) {
            if (s.size() == 0) {
                return false;
            }
            vector<int> next;
            next = getNext(s);
            int len = s.size();
            if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) {
                return true;
            }
            return false;


        }
    
};


//int main() {
//    string a = "mississippi";
//    string b = "issip";
//    Solution A;
//    vector<int> x = A.getNext(b);
//    for (auto k : x)
//    {
//        cout << k << " ";
//    }
//    
//   
//       /* cout << A.strStr(a,b) << " ";*/
//
//    return 0;
//}