#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
    int search(vector<int>& nums, int target) {

        if (nums.size() == 1) 
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        
        // Find pivot

        int pivot;
        int pivot_index;

        int L_index = 0;
        int R_index = nums.size() - 1;

        while ((R_index - L_index) != 1)
        {

            int L = nums[L_index];
            int R = nums[R_index];

            if (L < R)
            {
                pivot = L;
                pivot_index = 0;
                break;
            }
            else 
            {
                int M_index = (L_index+R_index)/2;
                int M = nums[M_index];
                if (M > L)
                {
                    L_index = M_index;
                }
                else 
                {
                    R_index = M_index;
                }
            }
        }

        int L = nums[L_index];
        int R = nums[R_index];

        if (L < R)
        {
            pivot_index = L_index;
            pivot = L;
        } else
        {
            pivot_index = R_index;
            pivot = R;
        }

        // Start binary search

        if (nums[0] <= target && target <= p)
        {
            L_index = 0;
            R_index = pivot_index;
        } else
        {
            L_index = pivot_index;
            R_index = nums.size()-1;
        }

        if (pivot_index == nums.size()-1)
        {
            if (nums[nums.size()-1] == target)
            {
                return nums.size()-1;
            }
            else 
            {
                L_index = 0;
                R_index = nums.size()-2;
            }
        }
        else if (pivot_index == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                L_index = 1;
                R_index = nums.size()-1;
            }
        }
        else if (pivot_index == 0)
        {
            L_index = 0;
            R_index = nums.size()-1;
        }
        
        while (L_index <= R_index)
        {
            L = nums[L_index];
            R = nums[R_index];

            int mid_index = (L_index + R_index) / 2;
            int mid = nums[mid_index];

            if (target < mid)
            {
                R_index = mid_index-1;
            }
            else if (target > mid)
            {
                L_index = mid_index+1;
            }
            else 
            {
                return mid_index;
            }
        }

        return -1;

    }




int main() 
{
    // Test cases
    vector<int> input = {4,5,6,7,0,1,2};
    
    int ans = search(input, 1);
    
    return 0;
}