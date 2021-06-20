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

class Solution6 {
   public:
    void inputLinkedNode() {
        string oneLine;
        getline(cin, oneLine);
        stringstream input(oneLine);
        vector<int> vecLinkNode;
        for (int i; input >> i;) {
            vecLinkNode.push_back(i);
            if (input.peek() == ',') input.ignore();
        }
        printAfterLinkNode(vecLinkNode);
    }
    void printAfterLinkNode(const vector<int> &vec) {
        if (vec.size() == 1) {
            cout << vec[0] << endl;
            return;
        }
        bool hasOnePrint = false;
        int lastOne = -1;
        unsigned int i = 0;
        for (; i < vec.size() - 1;) {
            if (vec[i] != vec[i + 1] && vec[i] != lastOne) {
                if (hasOnePrint) {
                    cout << "," << vec[i];
                } else {
                    cout << vec[i];
                    hasOnePrint = true;
                }
                i++;
            } else {
                if (vec[i] == lastOne) {
                    i++;
                } else {
                    lastOne = vec[i];
                    i = i + 2;
                }
            }
        }
        if (i == vec.size() - 1 && vec[i] != lastOne) {
            if (hasOnePrint)
                cout << "," << vec[i] << endl;
            else
                cout << vec[i] << endl;
        }
    }
};

int main () {
    Solution6 sol;
    int i = 0;
    sol.inputLinkedNode();
    return 0;
}

//题目：给第一个链表（实际输入的是数组），删除重复的节点

//输入：
// 1,1,1,2

//输出：
// 2
