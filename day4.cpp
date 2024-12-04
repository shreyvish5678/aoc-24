#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const vector<pair<int, int>> directions = {
    {0, 1},   
    {0, -1},  
    {1, 0},  
    {-1, 0}, 
    {1, 1},  
    {-1, -1}, 
    {1, -1},  
    {-1, 1}  
};

bool findWord(const vector<string>& grid, int row, int col, const string& word, int dirRow, int dirCol) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int wordLen = word.length();

    for (int i = 0; i < wordLen; ++i) {
        int newRow = row + i * dirRow;
        int newCol = col + i * dirCol;

        if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) {
            return false; 
        }
        if (grid[newRow][newCol] != word[i]) {
            return false; 
        }
    }
    return true; 
}

int countOccurrences(const vector<string>& grid) {
    const string word = "XMAS";
    int numRows = grid.size();
    int numCols = grid[0].size();
    int wordLen = word.length();
    int count = 0;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            for (const auto& [dirRow, dirCol] : directions) {
                if (findWord(grid, row, col, word, dirRow, dirCol)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<string> grid;
    ifstream inFile("day4.txt");
    if (!inFile.is_open()) {
        cerr << "File not found" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        grid.push_back(line);
    }
    inFile.close();

    int result = countOccurrences(grid);
    cout << result << endl; 

    return 0;
}
