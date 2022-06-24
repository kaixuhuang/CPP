#include<iostream>
#include<set>
#include<map>
#include <unordered_map>
#include<array>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    //242
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
    //49
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;//����һ����ϣ����������str��Ϊkeyֵ������ǰ����Ϊvalueֵ
        for (string str:strs)
        {
            string s = str;
            sort(str.begin(), str.end());
            hash[str].emplace_back(s);
        }
        for (auto x : hash)//����
        
            ans.emplace_back(x.second);
        
        return ans;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int>  result;
        if (s.length() < p.length() && (s.length() == 0 || p.length()))
            return {};
        int cur;
        int len = p.length();
        string tmp;
        vector<int> pcount(26);
        vector<int> scount(26);
        for (cur = 0; cur < len; cur++)
        {
            pcount[p[cur] - 'a']++;//��¼ǰxλ��hash
            scount[s[cur] - 'a']++;
        }
        
        if (pcount == scount)
            result.emplace_back(0);
        for (cur = 0; cur <=s.length() - len; cur++)
        {
            scount[s[cur] - 'a']--;
            scount[s[cur + len] - 'a']++;//ɾȥǰһλ�ļ�¼ ��Ӻ�һλ�ļ�¼ �����ǻ�������
            if (pcount == scount)
                result.emplace_back(cur + 1);
        }

        return result;
        

    }




};
int main() {




    string a = "cbaebabacd";
    string b = "abc";
    Solution A;
    vector<int>::iterator it;
    vector<int> c;
    c = A.findAnagrams(a, b);
 

    //if (A.isAnagram(a, b))
    //    cout << "true";
    //else
    //    cout << "false";


    //string  a = "��úܸ�����ʶ��";
    //char b = '��';
    //cout << b;
    ////vector<
    ////sort(a.begin(), a.end());


}