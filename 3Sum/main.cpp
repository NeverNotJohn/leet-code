#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
    
vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        set<vector<int>> mySet;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++)
        {
            int target = nums[i] - (2 * nums[i]);

            int left_index = i + 1;
            int right_index = nums.size()-1;

            while (left_index < right_index)
            {
                int low = nums[left_index];
                int high = nums[right_index];
                int sum = high + low;

                cout << "left: " << left_index << endl;
                cout << "right: " << right_index << endl;

                if (sum == target)
                {
                    vector<int> subAns = {nums[i], low, high};
                    
                    if (mySet.find(subAns) == mySet.end())
                    {
                        ans.push_back(subAns);
                        mySet.insert(subAns);
                    }

                    right_index--;
                } else if (sum > target)
                {
                    right_index--;
                } else
                {
                    left_index++;
                }

            }
        }
        
        return ans;
    }

int main() 
{
    // Test cases
    vector<int> input = {-12,-1,4,-14,0,10,7,-7,-6,9,6,-2,7,13,9,-1,4,12,9,4,14,0,-4,0,0,10,2,-7,7,-4,-11,10,2,8,4,-12,-4,-12,-4,-3,12,9,11,4,-1,-3,10,-12,-6,-4,-1,-14,3,2,-7,-11,-3,10,-11,-10,13,-15,7,0,0,-4,-5,11,0,-2,-14,-11,-8,12,1,-1,-14,-12,-6,-5,0,9,-4,-12,-4,4,14,9,-9,10,14,-11,10,6,-3,-4,10,-1,14,-13,13,7,-9,12,4,-1,-4,5,3,6,8,10,0,11,13,11,-7,5,-3,-1,0,-4,-4,-4,10,0};
    
    threeSum(input);
    
    return 0;
}