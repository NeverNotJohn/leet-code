#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
    
bool isValidSudoku(vector<vector<char>>& board) {
    

    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> columns(9);
    vector<unordered_set<char>> boxes(9);

    for (int i = 0; i < board.size(); i++) {  // loop thru board
    
        vector<char> col = board[i];

        for (int j = 0; j < col.size(); j++) // loop thru col
        {
            char letter = col[j];
            
            if (letter != '.')
            {

                if (rows[j].find(letter) == rows[j].end() && columns[i].find(letter) == columns[i].end() && boxes[(j / 3) + (3 * (i / 3))].find(letter) == boxes[(j / 3) + (3 * (i / 3))].end())
                { // ISNT in sets
                    rows[j].insert(letter);
                    columns[i].insert(letter);
                    boxes[(j / 3) + (3 * (i / 3))].insert(letter);
                }
                else // IS in set
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() 
{
    // Test cases
    vector<vector<char>> input = {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
    bool ans = isValidSudoku(input);
    
    return 0;
}