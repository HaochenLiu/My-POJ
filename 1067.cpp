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

void win() {
    cout<<"1"<<endl;
}

void lose() {
    cout<<"0"<<endl;
}

/*
这里保存了特例。先检验是不是特例。不是特例，返回0
*/
int testException(int B) {
    if(165580140 == B) {
        return 267914295; 
    } else if(228826126 == B) {
        return 370248450; 
    } else if(292072112 == B) {
        return 472582605; 
    } else if(331160281 == B) {
        return 535828591; 
    } else if(355318098 == B) {
        return 574916760; 
    } else if(394406267 == B) {
        return 638162746; 
    } else if(433494436 == B) {
        return 701408732 ; 
    } else if(457652253 == B) {
        return 740496901 ; 
    } else if(496740422 == B) {
        return 803742887; 
    } else if(520898239 == B) {
        return 842831056; 
    } else if(545056056 == B) {
        return 881919225;     
    } else if(559986408 == B) {
        return 906077042; 
    } else if(584144225 == B) {
        return 945165211; 
    } else if(599074577 == B) {
        return 969323028; 
    } else {
        return 0;
    }
}

/*
石子数较少的为B，较多的为A
如果是A = B 或者 B = 0 ，必胜
（1，2）必败  其余（1，n）必胜
（2，n）必胜，因为上面出现过2
（3，5）必败  其余（3，n）必胜
（4，7）必败  其余（4，n）必胜
（5，n）必胜，因为上面出现过5
（6，10）必败  其余（6，n）必胜
依次类推，生成
每一个括号里的前一个数，都是依次得到
如果前一个数在之前出现过，则必胜
否则考察后一个数，通过差分得到。差分1，2，3，4.。。。
只有A等于后一个数时，必败。否则必胜。
考虑数字组
（A, B）   i
（1，2）   1
（3，4）   2
（4，7）   3
（6，10）  4
（8，13）  5
（9，15）  6
发现A都是 i*1.618...(黄金分割) 之后，再取整。只有少数例外
将例外存在程序中。这样此问题得以解决。时间O(1)
*/

int main() {
    int A,B;
    while(cin>>A>>B) {
        if(A < B) {
            int tmp = A;
            A = B;
            B = tmp;
        }
        
        if(A == B || B == 0) {
            win();
        } else {
            int i = int(B*((sqrt(5.0) - 1) / 2));
            if(int((i + 1) * ((sqrt(5.0) + 1) / 2)) != B && int(i *((sqrt(5.0) + 1) / 2)) != B) {
                win();
                continue;
            }

            int bound = testException(B);
            if(bound == 0) {
                bound = i + 1 + B;
            }
            if(A == bound) {
                lose();
            } else {
                win();
            }
        }
    }
    return 0;
}
