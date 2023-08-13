#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int ans = 0;
        int counter = 0;

        if (position.size() == 1) { return 1; }

        while (counter != position.size() - 1)
        {

            bool fleet = true;
            unordered_map<int, int> carMap;

            for (int i = 0; i < position.size(); i++)
            {
                int pos = position[i];
                int sp = speed[i];

                if (pos == target)
                {
                    if (fleet) 
                    {
                        ans++;
                        fleet = false;
                    }
                    position[i] = 0;
                    speed[i] = 0;
                    counter++;

                    continue;
                }
                
                position[i] = position[i] + speed[i];

                pos = position[i];
                sp = speed[i];

                if (carMap.find(pos) != carMap.end())
                {
                    if (sp < speed[carMap[pos]])
                    {
                        speed[carMap[pos]] = sp;   
                        carMap[pos] = i;
                    }
                    else
                    {
                        speed[i] = speed[carMap[pos]];
                    }
                }
                else
                {
                    carMap[pos] = i;
                }
                

            }
        }
        return ans + 1;
    }

int main() 
{
    // Test cases
    vector<int> position = {0,2,4}; 
    vector<int> speed = {4,2,1};
    int ans = carFleet(100, position, speed);
    
    return 0;
}