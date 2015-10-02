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

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int a[10001];

int main() {
    memset(a, 0, sizeof(a));
    int res = 1;
    int maxCnt = 1;
    for(int i = 1; i <= 10000; i++) {
        long long n = i;
        int cnt = 1;
        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            cnt++;
        }
        a[i] = cnt;
    }

    int maxVal = 0;
    int start;
    int end;
    while(cin>>start>>end) {
        cout<<start<<" "<<end<<" ";
        if(start > end) {
            int tmp = start;
            start = end;
            end = tmp;
        }
        maxVal = 0;
        for(int i = start; i <= end; i++) {
            maxVal = max(maxVal, a[i]);
        }
        cout<<maxVal<<endl;        
    }

    return 0;
}
