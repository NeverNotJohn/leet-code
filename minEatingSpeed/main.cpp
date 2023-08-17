#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
    int divideAndRoundUp(int numerator, int denominator) {
        // Perform the division
        int quotient = numerator / denominator;
        int remainder = numerator % denominator;

        // If there's a remainder, round up by adding 1 to the quotient
        if (remainder != 0) {
            quotient++;
        }
        return quotient;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int k;

        // Find max;
        int min = 1;
        int max = piles[0];
        for (int i = 1; i < piles.size(); i++)
        {
            if (piles[i] > max) { max = piles[i]; }
        }

        if (piles.size() == h)
        {
            return max;
        }

        // Determine k

        while (min <= max)
        {
            int mid = (min + max) / 2;

            // Calculate h
            int h_temp = 0;
            for (int x : piles)
            {
                h_temp = h_temp + divideAndRoundUp(x, mid);
            }

            if (h < h_temp)
            {
                min = mid + 1;
            }
            else if (h > h_temp)
            {
                max = mid - 1;
            }
            else
            {
                // find min k
                int k = mid;
                
                do
                {
                    k = mid;
                    mid--;
                    h_temp = 0;
                    for (int x : piles)
                    {
                        h_temp = h_temp + divideAndRoundUp(x, mid);
                    }
                } while (h_temp == h);
                
                return k;
            }
            
        }

        // can't find h... go down

        int h_temp = 0;

        do
        {
            
            k = min;
            min--;

            // find h
            for (int x : piles)
            {
                h_temp = h_temp + divideAndRoundUp(x, min);
            }

        } while (h_temp < h);

        return k;
    }

int main() 
{
    // Test cases
    vector<int> input = {12};
    
    minEatingSpeed(input, 11);
    
    return 0;
}