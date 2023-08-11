#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;
    
int evalRPN(vector<string>& tokens) {
    
    stack<int> data;

    for (string x : tokens)
    {

        if (x != "+" && x != "-" && x != "*" && x != "/")
        {
            int val = stoi(x);
            data.push(val);
        }
        else
        {
            int val2 = data.top();
            data.pop();
            int val1 = data.top();
            data.pop();

            char y = x[0];

            switch(y) 
            {
                case '+': {  
                    data.push(val1 + val2);
                    break;
                }
                case '-': {
                    data.push(val1 - val2);
                    break;
                }
                case '*': {
                    data.push(val1 * val2);
                    break;
                }
                case '/': {
                    data.push(val1 / val2);
                    break;
                }
            }
        }
    }

    return data.top();

}

int main() 
{
    // Test cases
    vector<string> input = {"2","-1","+","3","*"};
    
    int ans = evalRPN(input);
    
    return 0;
}