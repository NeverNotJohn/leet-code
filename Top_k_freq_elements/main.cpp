#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
    
vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<vector<int>> ans(nums.size(), {10001});
    vector<int> final_ans;
    unordered_map<int, int> intCount;
    unordered_set<int> nooms;

    for (int x : nums) // loop thru nums
    {
        intCount[x]++;
        nooms.insert(x);
    }

    for (int x : nooms) // loop thru set
    {   
        int count = intCount[x];
        int index = nums.size() - count;

        if (ans[index][0] == 10001)
        {
            ans[index] = {x};
        } else 
        {
            ans[index].push_back(x);
        }
    }

    for (int i = 0; i < ans.size(); i++) // loop thru ans
    {
        if (k == 0) { break; }

        vector<int> temp = ans[i];

        if (temp[0] == 10001) { continue; }

        for (int x : temp) // loop thru inner ar
        {
            final_ans.push_back(x);
            k--;
        }
        
    }

    return final_ans;
}

int main() 
{
    // Test cases
    vector<int> input = {1,5,0,0,0,0,0,-221,-221,5};
    int k = 3;
    
    topKFrequent(input, k);
    
    return 0;
}