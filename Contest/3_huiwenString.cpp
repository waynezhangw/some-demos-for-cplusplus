#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution3 {
public:
    bool palindromeString(string str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i] == str[j]) {
                i++;
                j--;
            } else return false;
        }
        return true;
    }
};

int main () {
    Solution3 sol;
    string str;
    cin >> str;
    bool isOrNot = sol.palindromeString(str);
    if (isOrNot) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

//题目：判断一个字符串是否是回文串

//输入：
// saa

//输出：
// false
