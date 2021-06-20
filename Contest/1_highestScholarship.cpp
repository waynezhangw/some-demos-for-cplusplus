#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::endl;
using std::stringstream;

class Solution1 {
private:
    int studentsNum;
    vector<string> vecStudentsName;
    vector<int> averageScore;
    vector<int> dicussScore;
    vector<char> bossStudents;
    vector<char> westernStudents;
    vector<int> paperNum;

    string winner;
    int winnerScore;
    int sumScore; 
public:
    void inputAllStudentsData() {
        cin >> studentsNum;
        string oneLine;
        getline(cin,oneLine);   //deal with buffer from previous cin
        for (int i = 0;i < studentsNum;i++) {
            getline(cin,oneLine);
            string tmpResult;
            stringstream input(oneLine);
            vector<string> tmpVec;
            while(input>>tmpResult) {
                tmpVec.push_back(tmpResult);
            }
            vecStudentsName.push_back(tmpVec[0]);
            averageScore.push_back(std::stoi(tmpVec[1]));
            dicussScore.push_back(std::stoi(tmpVec[2]));
            bossStudents.push_back(tmpVec[3][0]);
            westernStudents.push_back(tmpVec[4][0]);
            paperNum.push_back(std::stoi(tmpVec[5]));
        }
    }
    
    void calculateScore() {
        winnerScore = 0;
        sumScore = 0;
        for (unsigned int i = 0;i < vecStudentsName.size();i++) {
            sumScore += obtainScholarship(i);
        }
        cout << winner << endl;
        cout << winnerScore << endl;
        cout << sumScore << endl;
    }

    int obtainScholarship(int i) {
        int money = 0;
        //1.院士奖学金
        if (averageScore[i] > 80 && paperNum[i] > 0) money += 8000;
        //2.五四奖学金
        if (averageScore[i] > 85 && dicussScore[i] > 80) money += 4000;
        //3.成绩优秀奖
        if (averageScore[i] > 90) money += 2000;
        //4.西部奖学金
        if (averageScore[i] > 85 && westernStudents[i] == 'Y') money += 1000;
        //5.班级贡献奖
        if (dicussScore[i] > 80 && bossStudents[i] == 'Y') money += 850;
        if (money > winnerScore) {
            winner = vecStudentsName[i];
            winnerScore = money;
        }
        return money;
    }
};

int main() {
    Solution1 sol;
    sol.inputAllStudentsData();
    sol.calculateScore();
    return 0;
}

//题目：给定一些规则，计算最大可获得的奖学金数额

//输入：
// 4
// YaoLin 87 82 Y N 0
// ChenRuiyi 88 78 N Y 1
// LiXin 92 88 N N 0
// ZhangQin 83 87 Y N 1

//输出：
// ChenRuiyi
// 9000
// 28700