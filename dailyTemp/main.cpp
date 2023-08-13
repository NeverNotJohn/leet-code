#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> myStack;

        for (int i = 0; i < temperatures.size(); i++)
        {
            
            while (!myStack.empty() && myStack.top().first < temperatures[i])
            {
                int ind = myStack.top().second;
                ans[ind] = i - ind;
                myStack.pop();
            }
            
            pair<int, int> temp(temperatures[i], i);
            myStack.push(temp);

        }

        return ans;

    }

int main() 
{
    // Test cases
    vector<int> input = {73,74,75,71,69,72,76,73};
    
    dailyTemperatures(input);
    
    return 0;
}