#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int m = 0;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                m = max(m, prices[r] - prices[l]);
            }
            else{
                l = r;
            }
            r++;
        }
        return m;
    }
};

int main(){
    Solution s;
    vector<int> p = {10, 1, 5, 6, 7, 1};
    cout << s.maxProfit(p);
    return 0;
}