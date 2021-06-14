#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <fstream>

#include <dirent.h>

using std::cout;
using std::cin;
using std::string;


class Words {
public:
	Words(void) {
		allCounts = 0;
	}
	~Words(void) {}

	void countWord(const std::string &file_path) {
		std::ifstream myFile;
		myFile.open(file_path.c_str());
		int count = 0;
		string word;
		while (myFile >> word) {
			count++;
		}
		myFile.close();
		cout << file_path << ":" << count << std::endl;
		allCounts += count;
	}
	int readFromFile(std::ofstream &out, const std::string &dir_path) {
		if (!out.is_open()) {
			std::cout << "stream not open" << std::endl;
			return -1;
		}

		DIR *dir = opendir(dir_path.c_str());
		if (!dir) { 
			return -1;
		}
		struct dirent * dent;
		while ((dent = readdir(dir))) {
			if (dent->d_type == DT_DIR) {
				readFromFile(out, dir_path + dent->d_name);
			} else {
				out << dent->d_name << std::endl;
				vecFile.push_back(dir_path + "/" +dent->d_name);
			}
		}
		closedir(dir);
		return 0;
	}
	void checkVecFile() {
		cout << "Count consecutively:" << std::endl;
		for (unsigned int i = 0;i < vecFile.size();i++) {
			countWord(vecFile[i]);
		}
	}

	int getVecFileSize() { return vecFile.size(); }
	string getVecFileByIndex(int i) { return vecFile[i]; }
	int getAllCounts() { return allCounts; }

private:
	std::vector<string> vecFile;
	int allCounts;
};	


int main () {
	Words myWord;
	std::ofstream out("files.txt");
	// must without '/' at the end of dir_path if you want to count file with depth=1
	int ret = myWord.readFromFile(out, "/tmp/javaFile");
	if (ret != 0) cout << "readFromFile wrong!" << std::endl;
	out.close();
	//myWord.checkVecFile();

	cout << "Count concurrently:" << std::endl;
	std::vector<std::thread> threads;
	for (int i = 0;i < myWord.getVecFileSize();i++) {
		threads.push_back(std::thread(&Words::countWord, &myWord, myWord.getVecFileByIndex(i)));
	}
	for (auto &th : threads) {
		th.join();
	}

	cout << "sum all: " << myWord.getAllCounts() << std::endl;
	return 0;
}

/*
C++中阶（上）：
题目1：采用多线程统计指定目录下的所有文件的单词个数，按照指定格式输出。

输入：文件路径：/home/learning/words-count

条件说明：每个文件大小不同有的可能很大，有的可能很小

输出：输出单个文件的单词个数以及所有文件单词个数的总和

     a.txt 1000000

     b.txt 2000000

      ….

     sum(a…n) = 1200000000
*/



