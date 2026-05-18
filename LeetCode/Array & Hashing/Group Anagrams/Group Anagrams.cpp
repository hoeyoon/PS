#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> r;
        for(auto &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            r[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &it : r){
            result.push_back(it.second);
        }
        return result;
    }
};
