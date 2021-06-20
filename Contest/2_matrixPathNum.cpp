#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;
using std::vector;

class Solution2 {
   private:
    int M, N;

   public:
    void inputMatrix() {
        string oneLine;
        getline(cin, oneLine);
        stringstream input(oneLine);
        vector<int> tmpVec;
        for (int i; input >> i;) {
            tmpVec.push_back(i);
            if (input.peek() == ',') input.ignore();
        }
        M = tmpVec[0];
        N = tmpVec[1];
        long pathNum2 = calculatePathNum2(M, N);
        cout << pathNum2 << endl;
        //cout << pathNum1 << "," << pathNum2 << "," << (pathNum1 == pathNum2) << endl;
    }

    int calculatePathNum(int m, int n) {  //递归会很慢
        if (m == 1 || n == 1) return 1;
        if (m == 2 && n == 2) return 2;
        return calculatePathNum(m - 1, n) + calculatePathNum(m, n - 1);
    }

    long calculatePathNum2(int m, int n) {  //for
        // Create a 2D table to store results of subproblems
        long count[m][n];

        // Count of paths to reach any cell in first column is 1
        for (int i = m - 1; i >= 0; i--)
            count[i][0] = 1;

        // Count of paths to reach any cell in last row is 1
        for (int j = 0; j < n; j++)
            count[m - 1][j] = 1;

        // Calculate count of paths for other cells in
        // bottom-up manner using the recursive solution
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 1; j < n; j++)
                //left one come here and bottom one come here
                count[i][j] = count[i][j - 1] + count[i + 1][j];
        }
        return count[0][n - 1];
    }
};

int main() {
    Solution2 sol;
    sol.inputMatrix();
    return 0;
}

//题目：M*N的棋盘格，左下角都右上角共有多少条可走的路

//输入：
// 4,4

//输出：
// 20