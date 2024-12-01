#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    std::string filePath = "day1.txt";
    std::vector<int> list1;
    std::vector<int> list2;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            list1.push_back(num1);
            list2.push_back(num2);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }
    file.close();
    bubbleSort(list1);
    bubbleSort(list2);
    int sum = 0;
    for (int i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }
    std::cout << "Sum of the absolute differences: " << sum << std::endl;
    int total = 0;
    for (int i = 0; i < list1.size(); i++) {
        int current = list1[i];
        int count = 0;  
        for (int j = 0; j < list2.size(); j++) {
            if (current == list2[j]) {
                count++;
            }
        }
        total += count * current;
    }
    std::cout << "Total: " << total << std::endl;
}