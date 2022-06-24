#include<iostream>
#include<set>
#include<map>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
   /* bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        multiset<char> a, b;
        int i ;
        for (i = 0; i < m; i++)
            a.insert(s[i]);
        for (i = 0; i < n; i++)
            b.insert(t[i]);
        if (a.size() != b.size())
            return false;
        else {
            set<char>::iterator it;
            set<char>::iterator it1;
            for (it = a.begin(), it1 = b.begin(); it != a.end(); it++, it1++)
                if (*it1 != *it) {
                    return false;
                    break;
                }
        }
        return true;
    }*/
    bool isAnagram(string s, string t) {
        vector<char> vec1,vec2;
        vec1.assign(s.begin(), s.end());
        vec2.assign(t.begin(), t.end());
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        return vec1 == vec2;
    }

};
int main() {



    //string a = "avbca";
    //string b = "abcva";
    //Solution A;
    //if (A.isAnagram(a, b))
    //    cout << "true";
    //else
    //    cout << "false";


    //string  a = "你好很高兴认识你";
    //char b = '你';
    //cout << b;
    ////vector<
    ////sort(a.begin(), a.end());


}