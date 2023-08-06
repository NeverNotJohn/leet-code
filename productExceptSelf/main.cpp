#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        vector<int> minor;
        vector<int> major;

        minor[0] = nums[0]; // product of everything to the left
        major[major.size() - 1] = nums[0]; // product of everything to the right 

        for (int i = 1; i < nums.size(); i++) // loop thru nums... create minor
        {   
            minor[i] = minor[i-1] * nums[i];
        }

        for (int j = major.size() - 2; j >= 0; j++)
        {
            major[j] = major[j + 1] * nums[j];
        }

        return ans;

    }

int main() 
{
    // Test cases
    vector<int> input = {1,2,3,4,5};
    
    productExceptSelf(input);
    
    return 0;
}