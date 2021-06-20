#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

bool myCompareFunction(int i, int j) {
    return i < j;
}

class Solution8 {
   public:
    void inputLinkedNode() {
        int k = 1;
        string oneLine;
        getline(cin, oneLine);
        stringstream input(oneLine);
        vector<int> vecNumList;
        for (int i; input >> i;) {
            vecNumList.push_back(i);
            if (input.peek() == ',' || input.peek() == ' ') input.ignore();
        }
        k = vecNumList[0];
        cout << kthValue(vecNumList, k) << endl;
    }

    int kthValue(vector<int> &vec, int k) {
        sort(vec.begin()+1, vec.end(), myCompareFunction);
        return vec[vec.size() - k];
    }
};

int main() {
    Solution8 sol;
    sol.inputLinkedNode();
    return 0;
}

//题目：寻找未排序数组中第K（K >= 1 && K <= 数组长度）大的数

//输入：
// 2 3,2,1,5,6,4

//输出：
// 5


