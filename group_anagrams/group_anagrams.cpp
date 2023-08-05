#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


    
struct VectorHash {
    size_t operator()(const vector<int>& vec) const {
        size_t seed = vec.size();
        for (const int& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

struct VectorEqual {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
        return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
    }
};


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    int size = 0;
    vector<vector<string>> ans;
    unordered_map<vector<int>, int, VectorHash, VectorEqual> hashMap;

    for (int i = 0; i < strs.size(); i++) // loop thru strs
    {
        string main_string = strs[i];
        vector<int> charList(26, 0);

        for (int j = 0; j < main_string.size(); j++) // loop thru chars in string... create arr
        {
            char character = main_string[j];
            int charNum = character - 'a';
            
            charList[charNum]++;
        }

        if (hashMap.find(charList) != hashMap.end())
        {
            int ansIndex = hashMap[charList]; 
            ans[ansIndex].push_back(main_string);
        } else  
        {
            hashMap[charList] = size;
            size++;
            ans.push_back({main_string});
        }

    }

    return ans;
}


int main() 
{
    vector<string> strs = {"abc", "b", "c", "wsaf", "fuck"};
    
    groupAnagrams(strs);
    cout << "ah";
}