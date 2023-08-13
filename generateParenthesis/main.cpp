#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
void makePar(vector<string>& ans, int n, int l, int r, string s="")
{

    if (s.empty())
    {
        makePar(ans, n, l-1, r, "(");
        return;
    }

    if (l == 0)
    {
        while (r != 0)
        {
            s.append(")");
            r--;
        }
        ans.push_back(s);
    }
    else if (r == 1)
    {
        s.append("()");
        ans.push_back(s);
    } 
    else
    {

        string temp_l = s;
        string temp_r = s;

        makePar(ans, n, l-1, r, temp_l.append("("));
        makePar(ans, n, l, r-1, temp_r.append(")"));
    }

}

int main() 
{
    // Test cases
    int n = 3;
    vector<string> ans = {};

    makePar(ans, n, n, n);
    
    return 0;
}