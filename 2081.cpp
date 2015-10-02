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

int a[500001];
int b[3012501]; //0代表没出现过，1代表出现过

//在a[length]以前出现过n
bool exist(int n, int length) {
    for(int i = 0; i < length; i++) {
        if(a[i] == n) {
            return true;
        }
    }
    return false;
}

void init() {
    for(int i = 0; i <= 3012500; i++) {
        b[i] = 0;
    }

    for(int i = 1; i <= 500000; i++) {
        if(a[i - 1] > i && b[a[i - 1] - i] == 0) {//正数，并且没出现过
            a[i] = a[i - 1] - i;
            b[a[i - 1] - i] = 1; //标记出现过
        } else {
            a[i] = a[i - 1] + i;
            b[a[i - 1] + i] = 1; //标记出现过
        }
    }
}

int main() {
    init();
    int N;
    while(cin>>N) {
        if(N == -1) {
            break;
        }
        
        cout<<a[N]<<endl;
    }
    return 0;
}
