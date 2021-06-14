#include "thirdparty/gtest/gtest.h"  //gtest 1.6.0 will not work here
//#include "gtest/gtest.h"
#include "binary_search.h"

#include <algorithm>

TEST(BinarySearchTest, test1) {
    vector<int> base_vec = {10, 20, 30, 30, 20, 10, 10, 20, 31}; // 10 10 10 20 20 20 30 30 31
    vector<int> target_vec = {0, 10, 11, 20, 21, 30, 31, 40};
    for (unsigned int i=0;i<target_vec.size();i++) {
        EXPECT_EQ( lower_bound(base_vec, target_vec[i]), 
            std::lower_bound(base_vec.begin(), base_vec.end(), target_vec[i]) - base_vec.begin() );
    }
}

int main (int argc, char **argv) {
    //vector<int> vec = {10, 20, 30, 30, 20, 10, 10, 20, 31}; // 10 10 10 20 20 20 30 30 31
    //vector<int> vec = {0, 2, 2, 1, 1, 2, 30, 31, 19}; 
    // vector<int> vec = {1}; 
    // cout<<lower_bound(vec, atoi(argv[1]) )<<endl;
    // cout<<upper_bound(vec, atoi(argv[1]) )<<endl;
    // return 0;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}