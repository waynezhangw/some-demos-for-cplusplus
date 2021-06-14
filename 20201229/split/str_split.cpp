#include "str_split.h"
#include "thirdparty/gtest-1.6.0/include/gtest/gtest.h"

#include<sstream>

std::vector<std::string> split(const std::string& input, char sep) {
    std::vector<std::string> vec_ret;
    if (input.size() == 0) return vec_ret;
    std::istringstream sin(input);
    string field;
    while (getline(sin, field, sep)) {
        vec_ret.push_back(field);  
    }
    return vec_ret;
}

void printVec(const vector<string> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
}

int main (int argc, char const *argv[]) {
    vector<string> str_test = {"   ", "there is an adorable dog on my couch", "10.193.29.255"};
    char sep = argv[1][0];
    for (unsigned int i = 0;i < str_test.size();i++) {
        printVec( split(str_test[i], sep) );
        cout<<i<<" test done-------------"<<endl<<endl;
    }
    return 0;
}