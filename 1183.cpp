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
#include <hash_map>
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

using namespace stdext; // 用hash_map需要加上这一句
using namespace std;

/*
a = (bc - 1) / (b+c)
(b-a)(c-a) = 1 + a^2
b = a^2 + a + 1
c = a + 1
b + c = a^2 + 2a + 2
但题目要求给出最小的解
所以分解因数
*/
int main() {
    unsigned int a;
    cin>>a;
    unsigned int tmp = sqrt((double)(a * a + 1));
    for(unsigned int i = tmp; i >= 1; i--) {
        if((a * a + 1) % i == 0) {
            cout<<(2 * a + (a * a + 1) / i + i)<<endl;
            break;
        }
    }
    return 0;
}
