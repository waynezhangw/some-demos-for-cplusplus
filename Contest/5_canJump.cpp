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

class Solution5 {
   private:
    int n;
    vector<int> vec;

   public:
    void inputVec() {
        cin >> n;
        string oneLine;
        getline(cin, oneLine);  //deal with buffer from previous cin
        getline(cin, oneLine);
        string tmpResult;
        stringstream input(oneLine);
        while (input >> tmpResult) {
            vec.push_back(std::stoi(tmpResult));
        }
        if (vec.size() != n) cout << "num wrong" << endl;
    }

    bool canJumpLast() {
        int j = 0;
        int index = 0;
        while (j < n) {
            j += vec[index];
            if (j == n - 1)
                return true;
            else if (j > n - 1)
                return false;
            else
                index = j;
            if (vec[index] == 0) return false;
        }
        return false;
    }
};

int main() {
    Solution5 sol;
    sol.inputVec();
    bool isOrNot = sol.canJumpLast();
    if (isOrNot)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}

//题目：给定一个非负整数数组，最初在数组的起点，数组中的每个元素代表你在该位置可以跳跃的最大长度
//     判断能否跳到最后一个位置

//输入：
// 5
// 3 2 1 0 4

//输出：
// 0
