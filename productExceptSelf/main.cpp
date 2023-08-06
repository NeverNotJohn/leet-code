#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> ans(nums.size(), 0);
    vector<int> minor(nums.size(), 0);
    vector<int> major(nums.size(), 0);

    minor[0] = nums[0]; // product of everything to the left
    major[major.size() - 1] = nums[major.size() - 1]; // product of everything to the right 

    for (int i = 1; i < nums.size(); i++) // loop thru nums... create minor
    {   
        minor[i] = minor[i-1] * nums[i];
    }

    for (int j = major.size() - 2; j >= 0; j--) // create major
    {
        major[j] = major[j + 1] * nums[j];
    }

    // calculate answer

    ans[0] = major[1];
    ans[nums.size() - 1] = minor[minor.size() - 2];  

    for (int i=1; i < nums.size()-1; i++)
    {
        ans[i] = minor[i-1] * major[i+1];
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