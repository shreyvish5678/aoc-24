#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool checkDiagonal(const vector<string>& grid, int row, int col, int dirRow1, int dirCol1, int dirRow2, int dirCol2) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    string pattern1 = "", pattern2 = "";

    for (int i = 0; i < 3; ++i) {
        int newRow = row + i * dirRow1;
        int newCol = col + i * dirCol1;

        if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) return false;
        pattern1 += grid[newRow][newCol];
    }

    for (int i = 0; i < 3; ++i) {
        int newRow = row + i * dirRow2;
        int newCol = col + i * dirCol2 + 2;

        if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) return false;
        pattern2 += grid[newRow][newCol];
    }

    return ((pattern1 == "MAS" || pattern1 == "SAM") && (pattern2 == "MAS" || pattern2 == "SAM"));
}

int countXMAS(const vector<string>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int count = 0;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (checkDiagonal(grid, row, col, -1, 1, -1, -1)) count++; 
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

    int result = countXMAS(grid);
    cout << result << endl;

    return 0;
}
