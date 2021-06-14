#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>         // std::chrono::seconds
#include <mutex>          // std::mutex

using std::cout;
using std::cin;
using std::string;
using std::vector;

std::mutex g_display_mutex;

class ThreadPrint {
public:
	ThreadPrint(void) {
		currentPos = 0;
	}
	~ThreadPrint(void) {}

	void getInput() {
		cout << "Your string:";
		cin >> strToPrint;
		cout << "Your thread number:";
		cin >> threadNum;
		if (threadNum <= 0 || threadNum >= 16) {
			cout << "thread number should be '> 0 && < 16' " << std::endl;
		}
	}

	void printCharAndThreadID(int index) {
		while (currentPos < getStringSize()) {  // try_lock until all char is printed
			if (g_display_mutex.try_lock()) {   // every thread will try this continuously
				if (currentPos % threadNum == index) {
					cout << strToPrint[currentPos] << " " << std::this_thread::get_id() << std::endl;
					currentPos++;
				}
				g_display_mutex.unlock();
			}
		}
	}
	
	int getThreadNum() { return threadNum; }
	int getStringSize() { return strToPrint.size(); }

private:
	string strToPrint;
	int threadNum;
	int currentPos;
};	

int main () {
	ThreadPrint tp;
	tp.getInput();
	vector<std::thread> threads;
	for (int i = 0;i < tp.getThreadNum();i++) {
		threads.push_back(std::thread(&ThreadPrint::printCharAndThreadID, &tp, i));
	}
	for (auto &th : threads) th.join();

	return 0;
}

/*
题目2：请使用n个线程交替打印输入的字符串列表，每个线程每次输出一个字符。

输入两行，第一行是待打印的字符串，第二行是n （0 < n < 16) 使用多少个线程

例如：输入：

     abcd123456789

     2              

    

输出：第一列 是打印的字符，第二列是对应的线程ID

a 123

b 221



作业要求：

每个同学以工号建一个目录将题目放到以下两个文件中:

    题目1： words_count.cpp 

    题目2： thread_print.cpp

作业仓库：

https://gitlab.vmic.xyz/cpp-training/cpp-basics-20210309
*/



