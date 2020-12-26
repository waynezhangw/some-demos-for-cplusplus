#include "sort.h"

// 1.bass class
SortBase::SortBase(void) {}
SortBase::~SortBase(void) {}

void SortBase::Sort(vector<int> &v, bool (*comp)(int &a, int &b)) {}
void SortBase::printVec(vector<int> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<",";
    }
    cout<<endl;
}
bool SortBase::ascending(int &x, int &y) {
    return x<y;
}
bool SortBase::descending(int &x, int &y) {
    return x>y;
}

//2. first derived class
class QuickSort : public SortBase {
public:
    virtual void Sort(vector<int> &v, bool (*comp)(int &a, int &b)) override {
        // TODO 实现快速排序
        cout<<"origi sort:";
        SortBase::printVec(v);
        this->quickSortSub(0, int(v.size()-1), v, comp);
        cout<<"quick sort:";
        SortBase::printVec(v);
    }
    void quickSortSub(int left, int right, vector<int> &vec, bool (*comp)(int &a, int &b)) {
        int i = left;
        int j = right;
        int baseValue = vec[left];
        while (i != j && i < j) {
            while (!comp(vec[j], baseValue) && i<j) j--;   // try to find a value smaller than baseValue
            while (!comp(baseValue, vec[i]) && i<j) i++;
            if(i == j) {
                vec[left] = vec[j];
                vec[j] = baseValue;
                break;
            }
            std::swap(vec[i], vec[j]);
        }
        if (left < j-1) quickSortSub(left, j-1, vec, comp);
        if (j+1 < right) quickSortSub(j+1, right, vec, comp);
    }
};

//3. second derived class
class HeapSort : public SortBase {
public:
    virtual void Sort(vector<int> &v, bool (*comp)(int &a, int &b)) override {
        // TODO 实现堆排序
        cout<<"orig sort:";
        SortBase::printVec(v);
        for (unsigned int i=0;i<v.size();i++) {
            std::make_heap(v.begin(), v.end()-i, comp);
            std::pop_heap(v.begin(), v.end()-i, comp);
        }
        cout<<"heap sort STL:";
        SortBase::printVec(v);
    }
    void buildHeap(vector<int> &vec, bool (*comp)(int &a, int &b)) {
        int heapSize = (int)vec.size();
        for (int i = heapSize/2;i >= 0;i--) {
            adjustHeap(vec, heapSize, i, comp);
        }
        cout<<"after building heap:";
        SortBase::printVec(vec);
    }
    void adjustHeap(vector<int> &vec, int heapSize, int index, bool (*comp)(int &a, int &b)) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < heapSize && !comp(vec[left], vec[largest])) largest = left;
        if (right < heapSize && !comp(vec[right], vec[largest])) largest = right;
        if (largest != index) {
            std::swap(vec[largest], vec[index]);
            this->adjustHeap(vec, heapSize, largest, comp);
        }
    }
    void heapSortHand(vector<int> &vec, bool (*comp)(int &a, int &b)) {
        cout<<"orig sort:";
        SortBase::printVec(vec);
        this->buildHeap(vec, comp);
        int currentSize = (int)vec.size();
        for (int i=1;i<(int)vec.size();i++) {
            std::swap(vec[0], vec[currentSize-i]);
            this->adjustHeap(vec, currentSize-i, 0, comp);
        }
        cout<<"heap sort hand:";
        SortBase::printVec(vec);
    }
};

//4. factory class
SortBase *SortFactory::GetSort(SORT_FUNC_T t, vector<int> &vec) {
    // TODO 实现工厂函数
    switch(t) {
        case QUICK_SORT: {
            QuickSort qk;
            qk.Sort(vec, SortBase::descending);
            break;
        }
        case HEAP_SORT_STL: {
            HeapSort hs;
            hs.Sort(vec, SortBase::ascending);
            break;
        }
        case HEAP_SORT: {
            HeapSort hs;
            hs.heapSortHand(vec, SortBase::ascending);
            break;
        }
        default: {
            cout<<"No match Sort Function!"<<std::endl;
            break;
        }
    }
    return nullptr;
}


int main() {
    SortFactory sf;
    std::vector<int> vec = {3,5,2,1,7,8,7,9,2,1};
    sf.GetSort(QUICK_SORT, vec);
    vec = {3,5,2,1,7,8,7,9,2,1};
    sf.GetSort(HEAP_SORT_STL, vec);
    vec = {3,5,2,1,7,8,7,9,2,1};
    sf.GetSort(HEAP_SORT, vec);
    return 0;
}
//         3
//     5      2
//  1    7  8    7
// 9 2  1

