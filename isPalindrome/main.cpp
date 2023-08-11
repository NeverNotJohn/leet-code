#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
bool isPalindrome(string s) {
        
        string new_s = "";

        // remove stuff from string

        for (char c : s) 
        {
            if (isalnum(c)) {
                new_s += tolower(c);
            }
        }

        if (new_s == "") { return true; }

        int size = new_s.size();

        for (int i = 0; i < size; i++)
        {
            char p1 = new_s[i];
            char p2 = new_s[size-(1 + i)];
            
            if (p1 != p2) { return false; }

        }

        return true;

}


int main() 
{
    // Test cases
    string input = "Hell oworld!";
    
    isPalindrome(input);
    
    return 0;
}