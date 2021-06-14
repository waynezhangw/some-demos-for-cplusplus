
#pragma once

#include <vector>
#include <iostream>

using namespace std;

// lower_bound, upper_bound 定义参考如下链接:
// http://www.cplusplus.com/reference/algorithm/lower_bound/
// http://www.cplusplus.com/reference/algorithm/upper_bound/

// 返回索引位置, 如果不存在符合条件的值，返回 -1
// inputs 数组为有序数组
int lower_bound(const std::vector<int>& inputs, int val);
int upper_bound(const std::vector<int>& inputs, int val);
