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
贪心法
先对体积求立方根，向小查找。找到能整除的，作为b
再对剩下的面积求平方根，向小查找。找到能整除的，作为c，长度为a
a>= b>= c
如果这样，那么对68就不能找到最优解
b = 4, a = 17, c = 1
实际上，b = c = 2时更好
所以取面积为bc，再进行一次分解。
*/

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) {
        int blocks;
        cin>>blocks;
        int a,b,c; //a>=b>=c
        
        int maxVal = 0;
        while(maxVal * maxVal * maxVal <= blocks) {
            maxVal++;
        }
        maxVal--;

        for(int j = maxVal; j >= 1; j--) {
            if(blocks % j == 0) {
                b = j;
                blocks /= j;
                break;
            }
        }

        maxVal = (int)sqrt((double)blocks);
        for(int j = maxVal; j >= 1; j--) {
            if(blocks % j == 0) {
                c = j;
                a = blocks / c;
                break;
            }
        }

        blocks = b * c;
        maxVal = (int)sqrt((double)blocks);
        for(int j = maxVal; j >= 1; j--) {
            if(blocks % j == 0) {
                c = j;
                b = blocks / c;
                break;
            }
        }

        cout<<2 * (a * b + b * c + c * a)<<endl;
    }
    return 0;
}
