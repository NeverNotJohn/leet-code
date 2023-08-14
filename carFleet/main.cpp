#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
    if (position.size() == 1) { return 1;}

    // CREATE SORTED PAIR VECTOR
    vector<pair<int, int>> pairs;

    for (int i = 0; i < position.size(); i++)
    {
        pair<int, int> temp(position[i], speed[i]);
        pairs.push_back(temp);
    }

    // Sort the array of pairs by the first item using a custom comparison function
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    // actual code:

    int ans = 1;
    double x = target-pairs[pairs.size()-1].first;
    double y = pairs[pairs.size()-1].second;
    double lead = x / y;
    
    for (int i = pairs.size()-2; i >= 0; i--)
    {
        double x = target-pairs[i].first;
        double y = pairs[i].second;
        double time = x / y;
        
        if (time > lead) // DOESN'T BECOME FLEET
        {
            lead = time;
            ans++;
        }
    }
    

    return ans;
    
}

int main() 
{
    // Test cases
    vector<int> position = {8,3,7,4,6,5}; 
    vector<int> speed = {4,4,4,4,4,4};
    int ans = carFleet(10, position, speed);
    
    return 0;
}