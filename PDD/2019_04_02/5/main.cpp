#include <iostream>


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;


/*
vector<string> getAll(string str){
    vector<pair<int,int>> ret;

    vector<pair<int,int>> len1;
    for (int i = 0; i < str.size(); ++i) {
        pair<int,int> p(i,i);
        len1.push_back(p);
        ret.push_back(p);
    }

    vector<pair<int,int>> len2;
    for (int i = 0; i< str.size() - 1; ++i) {
        if(str[i] == str[i + 1]){
            pair<int,int> p(i,i+1);
            len2.push_back(p);
            ret.push_back(p);
        }
    }

    while (!len1.empty() || !len2.empty() ){
        vector<pair<int,int>> nextLen1;
        for (int i = 0; i < len1.size(); ++i) {
            int left = len1[i].first - 1;
            int right = len1[i].second + 1;
            if(left >= 0 && right <= str.size() - 1 && str[left] == str[right]){
                pair<int,int> p(left,right);
                nextLen1.push_back(p);
                ret.push_back(p);
            }
        }
        swap(nextLen1,len1);

        vector<pair<int,int>> nextLen2;
        for (int i = 0; i < len2.size(); ++i) {
            int left = len2[i].first - 1;
            int right = len2[i].second + 1;
            if(left >= 0 && right <= str.size() - 1 && str[left] == str[right]){
                pair<int,int> p(left,right);
                nextLen2.push_back(p);
                ret.push_back(p);
            }
        }
        swap(nextLen2,len2);
    }
    vector<string> retStrVec;
    for (int j = 0; j < ret.size(); ++j) {
        string tmp = str;
        int start = ret[j].first;
        int end = ret[j].second + 1;
        retStrVec.push_back(tmp.substr(start,end - start));
    }
    return retStrVec;
}
*/



vector<string> getAll(string str){
    vector<pair<int,int>> ret;

    vector<pair<int,int>> len;
    for (int i = 0; i < str.size() - 1; ++i) {
        pair<int,int> p(i,i);
        len.push_back(p);   ret.push_back(p);
        if(str[i] == str[i + 1]){
            pair<int,int> p(i,i+1);
            len.push_back(p);  ret.push_back(p);
        }
    }
    pair<int,int> p(str.size() - 1,str.size() - 1);
    len.push_back(p);    ret.push_back(p);


    while (!len.empty()){
        vector<pair<int,int>> nextLen;
        for (int i = 0; i < len.size(); ++i) {
            int left = len[i].first - 1; int right = len[i].second + 1;
            if(left >= 0 && right <= str.size() - 1 && str[left] == str[right]){
                pair<int,int> p(left,right);
                nextLen.push_back(p);   ret.push_back(p);
            }
        }
        swap(nextLen,len);
    }

    vector<string> retStrVec;
    for (int j = 0; j < ret.size(); ++j) {
        int start = ret[j].first; int end = ret[j].second + 1;
        retStrVec.push_back(str.substr(start,end - start));
    }
    return retStrVec;
}


class Solution {
public:
    int countSubstrings(string str) {
        vector<pair<int,int>> ret;

        vector<pair<int,int>> len;
        for (int i = 0; i < str.size() - 1; ++i) {
            pair<int,int> p(i,i);
            len.push_back(p);   ret.push_back(p);
            if(str[i] == str[i + 1]){
                pair<int,int> p(i,i+1);
                len.push_back(p);  ret.push_back(p);
            }
        }
        pair<int,int> p(str.size() - 1,str.size() - 1);
        len.push_back(p);    ret.push_back(p);


        while (!len.empty()){
            vector<pair<int,int>> nextLen;
            for (int i = 0; i < len.size(); ++i) {
                int left = len[i].first - 1; int right = len[i].second + 1;
                if(left >= 0 && right <= str.size() - 1 && str[left] == str[right]){
                    pair<int,int> p(left,right);
                    nextLen.push_back(p);   ret.push_back(p);
                }
            }
            swap(nextLen,len);
        }

        vector<string> retStrVec;
        for (int j = 0; j < ret.size(); ++j) {
            int start = ret[j].first; int end = ret[j].second + 1;
            retStrVec.push_back(str.substr(start,end - start));
        }
        return retStrVec.size();
    }
};


int main() {
    string in = "ascdcss";
    vector<string> ret = getAll(in);
    for (string s : ret) {
        cout<<s<<endl;
    }
    return 0;
}