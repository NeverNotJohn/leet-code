#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
    
vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> ans(nums.size(), 0);
    vector<int> final_ans;
    unordered_map<int, int> intCount;
    unordered_set<int> nooms;

    for (int x : nums) // loop thru nums
    {
        intCount[x]++;
        nooms.insert(x);
    }

    for (int x : nooms) {   // loop thru set
        int count = intCount[x];
        ans[nums.size() - count] = x;
    }

    ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());

    for (int i = 0; i < k; i++)
    {
        final_ans.push_back(ans[i]);
    }

    return final_ans;
}


int main() 
{
    // Test cases
    vector<int> input = {1, 2, 3, 4, 5};
    int k = 5;
    
    topKFrequent(input, k);
    
    return 0;
}