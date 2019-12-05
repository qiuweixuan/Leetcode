#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <sstream>
#include <functional>
#include <bitset>
#include <numeric>
#include <cmath>
#include <regex>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res = "0";
        vector<int> count(256, 0), visit(256, 0);
        for (char c : s)
            count[c]++;

        for (char c : s)
        {
            count[c]--;
            if (visit[c] == 1)
                continue;
            else
            {
                while (res.size() > 0 && count[res.back()] > 0 && res.back() > c)
                {
                    visit[res.back()] = 0;
                    res.pop_back();
                }
                res += c;
                visit[c] = 1;
            }
        }

        res = res.substr(1);
        return res;
    }


    string removeDuplicateLettersByDFS(string s)
    {
        if (s.length() <= 0)
            return s;
        else
        {
            vector<int> count(26, 0);
            for (char c : s)
                count[c - 'a'] ++;
            int pos = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] < s[pos])
                    pos = i;
                count[s[i] - 'a']--;
                if (count[s[i] - 'a'] == 0)
                    break;
            }

            string tar = "";
            tar += s[pos];
            string left = getRes(s.substr(pos + 1), tar);
            return tar + removeDuplicateLetters(left);
        }
    }

    char getRes(string s, string tar)
    {
        int pos = s.find(tar);
        while (pos != s.npos)
        {
            s = s.replace(pos, tar.length(), "");
            pos = s.find(tar);
        }
        return s[0];
    }
};
