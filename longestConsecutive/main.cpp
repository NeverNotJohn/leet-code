#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
    
int longestConsecutive(vector<int>& nums) {

    if (nums.empty()) { return 0; }

    int ans = 1;
    unordered_set<int> mySet;
    vector<int> starts;

    for (int num : nums)    // make set
    {
        mySet.insert(num);
    }

    for (const auto& num : mySet)   // make starts... START OF STREAKS
    {
        if (mySet.find(num - 1) == mySet.end())
        {
            starts.push_back(num);
        }
    }

    for (int num : starts) // loop thru starts
    {
        int streak = 1;
        while (mySet.find(num + 1) != mySet.end()) // keep going until tail found
        {
            streak++;
            num++;
        }
        
        if (streak > ans)
        {
            ans = streak;
        }
    }

    return ans;

}

int main() 
{
    // Test cases
    vector<int> input = {100,3,2,1,6,8};
    
    longestConsecutive(input);
    
    return 0;
}