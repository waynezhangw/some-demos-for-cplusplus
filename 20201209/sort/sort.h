#pragma once

#include <iostream>
#include <vector>

using namespace std;

// 排序策略基类
class SortBase {
public:
  SortBase(void);
  virtual ~SortBase(void);
  // @v：待排序的数组
  // @comp：函数指针，用于排序时比较两个值的大小，返回true时a放前面
  virtual void Sort(vector<int> &v, bool (*comp)(int &a, int &b));

  void printVec(vector<int> &v);
  static bool ascending(int &x, int &y);
  static bool descending(int &x, int &y);
};

enum SORT_FUNC_T {
  SORT_FUNC_MIN = 0,
  QUICK_SORT,
  HEAP_SORT_STL,
  HEAP_SORT,
  SORT_FUNC_MAX,
  };

class SortFactory {
public:
  // Sort策略工厂
  // @t：排序方法，枚举值，用于指定排序方法
  // 返回值：排序策略基类指针
  static SortBase *GetSort(SORT_FUNC_T t, vector<int> &vec);

};
