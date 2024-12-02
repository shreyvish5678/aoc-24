#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

bool isSafe(std::vector<int> arr) {
    int n = arr.size();
    bool isDec = false;
    if (arr[0] > arr[1]) {
        isDec = true;
    }
    if (isDec) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] - arr[i + 1] >= 1 && arr[i] - arr[i + 1] <= 3) {
                continue;
            } else {
                return false;
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] >= 1 && arr[i + 1] - arr[i] <= 3) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool part2 = true;
    std::string fileName = "day2.txt";

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> data;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        int number;

        while (lineStream >> number) {
            row.push_back(number);
        }

        data.push_back(row);
    }

    inputFile.close();
    int total = 0;
    if (part2) {
        for (int i = 0; i < data.size(); ++i) {
            int n = data[i].size();
            for (int j = 0; j < n; j++) {
                std::vector<int> result;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        result.push_back(data[i][k]);
                    }
                }
                if (isSafe(result)) {
                    total++;
                    break;  
                }
            }
        }
    }
    else {
        for (int i = 0; i < data.size(); ++i) {
            if (isSafe(data[i])) {
                total++;
            }
        }
    }
    std::cout << "Total: " << total << std::endl;
    return 0;
}
