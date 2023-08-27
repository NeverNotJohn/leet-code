#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>



using namespace std;
    
    int lengthOfLongestSubstring(string s) {
        
        int ans = 1;
        unordered_set<char> chars;

        if (s.size() == 1 || s.size() == 0)
        {
            return s.size();
        }

        int L_index = 0;
        int R_index = 0;

        int temp_ans = 1;

        chars.insert(s[0]);

        while(R_index < s.size()-1)
        {
            char L = s[L_index];
            char R = s[R_index];

            char next = s[R_index+1];
            
            if (chars.find(next) == chars.end()) // char is UNIQUE
            {
                R_index++;
                temp_ans++;
                chars.insert(next);
            }
            else 
            {

                if (temp_ans > ans)
                {
                    ans = temp_ans;
                }


                while (L != next && L_index < R_index-1)
                {
                    chars.erase(L);
                    L_index++;
                    L = s[L_index];
                    temp_ans--;
                }
                
                if (L_index == R_index-1)
                {
                    L_index++;
                    chars.erase(L);
                    R_index++;
                    chars.insert(s[R_index]);
                    continue;
                } 

                L_index++;
                chars.erase(L);
                temp_ans--;
            }
        }

        if (temp_ans > ans)
        {
            ans = temp_ans;
        }

        return ans;
    }

int main() 
{
    // Test cases
    string input = "pwwkew";
    
    int ans = lengthOfLongestSubstring(input);
    
    return 0;
}