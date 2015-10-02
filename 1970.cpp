#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

/*
棋盘周围围着一圈0，程序好写
1-19,1-19为棋盘
*/
int a[21][21];

//第i行第j列开始，横行是否有赢
bool testline(int line , int col) {
    if(line > 15 || a[line][col] == 0) return false;
    bool same = true;
    for(int i = 1; i < 5; i++) {
        if(a[line + i][col] != a[line][col]) {
            same = false;
            break;
        }
    }
    if(!same) {
        return false;
    } else {
        if(a[line][col] == a[line - 1][col] || a[line][col] == a[line + 5][col]) {
            return false;
        } else {
            return true;
        }
    }
}

//第i行第j列开始，竖着是否有赢
bool testcol(int line , int col) {
    if(col > 15 || a[line][col] == 0) return false;
    bool same = true;
    for(int i = 1; i < 5; i++) {
        if(a[line][col + i] != a[line][col]) {
            same = false;
            break;
        }
    }
    if(!same) {
        return false;
    } else {
        if(a[line][col] == a[line][col - 1] || a[line][col] == a[line][col + 5]) {
            return false;
        } else {
            return true;
        }
    }
}

bool testdiag1(int line , int col) {
    if(line > 15 || col > 15 || a[line][col] == 0) return false;
    bool same = true;
    for(int i = 1; i < 5; i++) {
        if(a[line + i][col + i] != a[line][col]) {
            same = false;
            break;
        }
    }
    if(!same) {
        return false;
    } else {
        if(a[line][col] == a[line - 1][col - 1] || a[line][col] == a[line + 5][col + 5]) {
            return false;
        } else {
            return true;
        }
    }
}

bool testdiag2(int line , int col) {
    if(line < 5 || col > 15 || a[line][col] == 0) return false;
    bool same = true;
    for(int i = 1; i < 5; i++) {
        if(a[line - i][col + i] != a[line][col]) {
            same = false;
            break;
        }
    }
    if(!same) {
        return false;
    } else {
        if(a[line][col] == a[line + 1][col - 1] || a[line][col] == a[line - 5][col + 5]) {
            return false;
        } else {
            return true;
        }
    }
}

//第i行第j列开始，是否有赢
bool test(int line , int col) {
    return (testline(line, col) ||
            testcol(line, col) ||
            testdiag1(line, col) ||
            testdiag2(line, col));
}

int main() {
    for(int line = 0; line < 21; line++) {
        for(int col = 0; col < 21; col++) {
            a[line][col] = 0;    
        }
    }

    int N;
    cin>>N;
    for(int count = 0; count < N; count++) {
        for(int line = 1; line <= 19; line++) {
            for(int col = 1; col <= 19; col++) {
                cin>>a[line][col];
            }
        }
        bool win = false;
        for(int line = 1; line <= 19; line++) {
            for(int col = 1; col <= 19; col++) {
                if(test(line, col)) {
                    cout<<a[line][col]<<endl;
                    cout<<line<<" "<<col<<endl;
                    win = true;
                    goto A;//跳出多层循环
                }
            }
        }
A:
        if(!win) {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
