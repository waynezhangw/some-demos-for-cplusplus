#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    // my function, it's shit
    bool match2(char* str, char* pattern) {    // too many conditions and it doesn't solve problem(a.*.*)
        int L1 = strlen(str);
        int L2 = strlen(pattern);
        if (L1 == 0 && L2 == 0) return true;        //1. two string all empty
        else if (L1 != 0 && L2 == 0) return false;  //2. string not empty but pattern empty
        else if (L1 == 0 && L2 != 0) {              //3. string empty but pattern not
            if (L2 % 2 != 0) return false;   
            else {
                for (int i=1;i<L2;i=i+2) {  // check ".*.*" like
                    if (pattern[i] != '*') return false;
                }
                return true;
            }
        }
        else {                                      //4. string and pattern both not empty
            int index1 = 0; 
            int index2 = 0;
            while (index1 < L1 && index2 < L2) {
                char c1 = str[index1];
                char c2 = pattern[index2];
                if (c1 != c2) {
                    if (c2 == '.') {
                        if (index2 == L2-1) return true;
                        else if (pattern[index2+1] != '*') {
                            index1++;
                            index2++;
                        }
                        else {
                            if (index2+2 < L2) index2 += 2;
                            else {
                                index1++;
                                index2 += 2;
                            }
                        }
                    }
                    else {
                        if (c2 == '*') return false;
                        else {
                            if (pattern[index2+1] == '*') index2 = index2 + 2;
                            else return false;
                        }
                    }
                }
                else {
                    index1++;
                    index2++;
                }
            }
            if (index1 == L1 && index2 == L2) return true;
            else return false;
        }
    }
    // some solution from the comments
    bool match(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0') return true;
        if (*str != '\0' && *pattern == '\0') return false;
        if (*(pattern+1) != '*') {
            if (*str == *pattern || (*str != '\0' && *pattern == '.')) return match(str+1, pattern+1);
            else return false;
        }
        else {
            if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
                //       skip two           and      match one or more
                return match(str, pattern+2) || match(str+1, pattern);
            }
            else {
                return match(str, pattern+2);  // current not match, '*' saves you
            } 
        }

    }
};


int main() {
    Solution sol;
    char str[] = "a";
    char pattern[] = "a*a";
    cout<<sol.match(str, pattern)<<endl;
    return 0;
}

