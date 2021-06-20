#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>      // std::accumulate

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;
using std::vector;
using std::accumulate;

class Solution7 {
   public:
    void inputMatrix() {
        vector<vector<int> > matrix;
        string oneLine;
        for (int i = 0; i < 8; i++) {
            vector<int> tmpVec;
            getline(cin, oneLine);
            string tmpResult;
            stringstream input(oneLine);
            while (input >> tmpResult) {
                tmpVec.push_back(std::stoi(tmpResult));
            }
            matrix.push_back(tmpVec);
        }
        if (isQueenHappy(matrix))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    bool isQueenHappy(const vector<vector<int> > &matrix) {
        // every row
        for (int i = 0; i < 8;i++) {
            int row = accumulate(matrix[i].begin(), matrix[i].end(), 0);
            if (row > 1) return false;
        }
        // every column
        for (int i = 0;i < 8;i++) {
            int column = 0;
            for (int j = 0;j < 8;j++) {
                column += matrix[j][i];
            }
            if (column > 1) return false;
        }
        // every diagonal
        int leftright = 0;
        int rightleft = 0;
        for (int i = 0;i < 8;i++) {
            leftright += matrix[i][i];
            rightleft += matrix[7 - i][i];
        }
        if (leftright > 1 || rightleft > 1) return false;
        return true;
    }
};

int main() {
    Solution7 sol;
    sol.inputMatrix();
    return 0;
}

//题目：8皇后摆放问题，任意两个皇后不得处在同一行、同一列、同一对角线上

//输入：
// 0 0 1 0 0 0 0 0 
// 0 0 0 0 0 1 0 0 
// 0 0 0 1 0 0 0 0 
// 1 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 1 
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 1 0 
// 0 1 0 0 0 0 0 0

//输出：
// true

