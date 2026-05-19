#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto &it : nums){
            m[it]++;
        }
        vector<pair<int, int>> arr;
        for(auto &it : m){
            arr.push_back({it.second, it.first});
        }
        sort(arr.rbegin(), arr.rend());
        
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }
        return result;
    }
};
