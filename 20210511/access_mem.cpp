#include <iostream>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;

int main() {
    const int one_million = 1000*1000;
    vector<int> vecTest;
    for (unsigned int i = 0;i < one_million;i++) {
        vecTest.push_back(99);
    }
    int tmp = 0;
    cout << "vec size:" << vecTest.size() << endl;

    auto start = std::chrono::steady_clock::now();
    for (unsigned int i = 0;i < vecTest.size();i++) {
        tmp = vecTest[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    //elapsed time will be different if initialize vecTest using: vector<int> vecTest(one_million, 99)
    cout << "1 million copy operations elapsed time: " << elapsed_seconds.count() * 1000 * 1000 * 1000 << " ns\n";
    cout << "access memory needs: " << elapsed_seconds.count() * 1000 * 1000 * 1000/one_million << " ns" << endl;
    return 0;
}


