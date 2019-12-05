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

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ret;
        if(s.size() == 0 || words.size() == 0){
            return ret;
        }

        set<string> uniWords;
        int wordLen = words[0].size();
        int wordSize = words.size();
        map<string,int> needCount;
        map<string,int> curCount;


        for (int i = 0; i < words.size(); ++i) {
            uniWords.insert(words[i]);
        }
        for (auto it = uniWords.begin(); it != uniWords.end(); ++it) {
           needCount[*it] = 0;
           curCount[*it] = 0;
        }

        for (int i = 0; i < words.size(); ++i) {
            needCount[words[i]]++;
        }



        for (int i = 0;  (i + 1) * wordLen <= s.size() ; ++i) {
            string curWord = s.substr(i  * wordLen, wordLen);
            curCount[curWord]++;

            if( i + 1 >= wordSize){
                bool isCompare = true;
                for (auto it = uniWords.begin(); it != uniWords.end(); ++it) {
                    if(needCount[*it] != curCount[*it]){
                        isCompare = false;
                        break;
                    }
                }
                if(isCompare){
                    int index = (i + 1 - wordSize ) * wordLen;
                    ret.push_back(index);
                }

                string prevWord = s.substr((i + 1 - wordSize)* wordLen,   wordLen);
                curCount[prevWord]--;
            }

        }


        return ret;
    }
};
*/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ret;
        if(s.size() == 0 || words.size() == 0){
            return ret;
        }

        unordered_map<string,int> needWordCounts;
        for (string word :words){
            needWordCounts[word]++;
        }

        int wordLen = words[0].size();
        int wordsSize = words.size();
        int strLen = s.size();

        for (int i = 0; i + wordsSize * wordLen <= strLen; ++i) {
            unordered_map<string,int> curWordCounts;
            bool isMatch = true;

            for (int j = 0; j  < wordsSize  ; ++j) {
                string word = s.substr(i + j * wordLen,wordLen);

                if(needWordCounts.find(word) != needWordCounts.end()){
                    curWordCounts[word]++;
                    if(curWordCounts[word] > needWordCounts[word]){
                        isMatch = false;
                        break;
                    }
                } else{
                    isMatch = false;
                    break;
                }
            }

            if(isMatch){
                ret.push_back(i);
            }

        }


        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "ABC";
    s.substr(0,1);
    cout<<s<<endl;
    return 0;
}