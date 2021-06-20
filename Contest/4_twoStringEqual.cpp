#include<iostream>
#include<string>
#include<stdlib.h>     /* abs */

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Solution4 {
public:
    bool twoString(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        for (int i = 0;i < str1.size();i++) {
            int c1 = int(str1[i]);
            int c2 = int(str2[i]);
            if (c1 == c2 || abs(c1-c2) == 32) continue;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution4 sol;
    string str1, str2;
    cin >> str1 >> str2;
    bool isOrNot = sol.twoString(str1, str2);
    if (isOrNot) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

//题目：比较两个字符串，忽略大小写看是否相等

//输入：
// saaz saas

//输出：
// false
