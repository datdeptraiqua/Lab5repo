// Name: Anton Rushevich
// UF ID: 62980854
// Partner: Minh Dat Lee

#include <iostream>
#include <vector>
#include <chrono>
#include "StringData.h"  // Assuming the header is named StringData.h

int linear_search(const std::vector<std::string>& container, const std::string& element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(const std::vector<std::string>& container, const std::string& element) {
    int left = 0;
    int right = container.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (container[middle] == element) {
            return middle;
        } else if (container[middle] < element) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<std::string>& lis = getStringData(); // Use the provided function to get the data
    std::string notStr = "not_here";
    std::string mStr = "mzzzz";
    std::string aStr = "aaaaa";

    auto timeBeg = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::cout << "Begin time: " << timeBeg.time_since_epoch().count() << std::endl;
    std::cout << std::endl;

    auto timea = std::chrono::high_resolution_clock::now();
    int a = linear_search(lis, notStr);
    auto timeaa = std::chrono::high_resolution_clock::now();
    double timeA = std::chrono::duration_cast<std::chrono::microseconds>(timeaa - timea).count();
    std::cout << "Linear search time for not_here: " << timeA << " microseconds" << std::endl;
    std::cout << "Index: " << a << std::endl;

    auto timea1 = std::chrono::high_resolution_clock::now();
    int a1 = binary_search(lis, notStr);
    auto timeaa1 = std::chrono::high_resolution_clock::now();
    double timeA1 = std::chrono::duration_cast<std::chrono::microseconds>(timeaa1 - timea1).count();
    std::cout << "Binary search time for not_here: " << timeA1 << " microseconds" << std::endl;
    std::cout << "Index: " << a1 << std::endl;
    std::cout << std::endl;

    auto timeb = std::chrono::high_resolution_clock::now();
    int b = linear_search(lis, mStr);
    auto timebb = std::chrono::high_resolution_clock::now();
    double timeB = std::chrono::duration_cast<std::chrono::microseconds>(timebb - timeb).count();
    std::cout << "Linear search time for mzzzz: " << timeB << " microseconds" << std::endl;
    std::cout << "Index: " << b << std::endl;

    auto timeb1 = std::chrono::high_resolution_clock::now();
    int b1 = binary_search(lis, mStr);
    auto timebb1 = std::chrono::high_resolution_clock::now();
    double timeB1 = std::chrono::duration_cast<std::chrono::microseconds>(timebb1 - timeb1).count();
    std::cout << "Binary search time for mzzzz: " << timeB1 << " microseconds" << std::endl;
    std::cout << "Index: " << b1 << std::endl;
    std::cout << std::endl;

    auto timec = std::chrono::high_resolution_clock::now();
    int c = linear_search(lis, aStr);
    auto timecc = std::chrono::high_resolution_clock::now();
    double timeC = std::chrono::duration_cast<std::chrono::microseconds>(timecc - timec).count();
    std::cout << "Linear search time for aaaaa: " << timeC << " microseconds" << std::endl;
    std::cout << "Index: " << c << std::endl;

    auto timec1 = std::chrono::high_resolution_clock::now();
    int c1 = binary_search(lis, aStr);
    auto timecc1 = std::chrono::high_resolution_clock::now();
    double timeC1 = std::chrono::duration_cast<std::chrono::microseconds>(timecc1 - timec1).count();
    std::cout << "Binary search time for aaaaa: " << timeC1 << " microseconds" << std::endl;
    std::cout << "Index: " << c1 << std::endl;

    return 0;
}

