#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>



using namespace std;
    
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        unordered_set<char> chars;

        if (s.size() == 1 || s.size() == 0)
        {
            return s.size();
        }

        int L_index = 0;
        int R_index = 0;

        while(R_index < s.size())
        {
            char L = s[L_index];
            char R = s[R_index];

            char next = s[R_index+1];
            
            if (chars.find(next) == chars.end()) // char is UNIQUE
            {
                R_index++;
                ans++;
                chars.insert(next);
            }
            else 
            {
                chars.erase(L);
                chars.insert(next);
                L_index++;
                R_index++;
            }
        }

        return ans;
    }

int main() 
{
    // Test cases
    string input = "abcabcbb";
    
    int ans = lengthOfLongestSubstring(input);
    
    return 0;
}