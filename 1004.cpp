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

int main() {
    double sum = 0;
    double tmp = 0;
    for(int i = 0; i < 12; i++) {
        cin>>tmp;
        sum += tmp;
    }
    sum /= 12;
    printf("$%.2lf\n", sum); //四舍五入，保留小数点后两位
    return 0;
}
