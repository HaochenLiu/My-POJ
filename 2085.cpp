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

int* a;

void reverse(int* a, int start, int end) {//把a[start]到a[end]翻转
    int delta = (end - start + 1) / 2;
    int tmp;
    for(int i = 0; i < delta; i++) {
        tmp = a[start + i];
        a[start + i] = a[end  - i];
        a[end - i] = tmp;
    }
}

void circle(int* a, int start, int end) {//把a[start]到a[end]向后移动一格，765变为576
    int tmp = a[end];
    for(int i = end; i > start; i--) {
        a[i] = a[i-1];
    }
    a[start] = tmp;
}

void solve(int N, int inv) {
    if(inv == 0) {
        for(int i = 1; i <= N; i++) {
            cout<<i<<" ";
        }
        return;
    }
    int len = (3.0 + sqrt(8.0 * inv - 7.0)) / 2.0;
    
    if(len % 2 == 0) {
        inv = (len / 2 * (len - 1)) - inv;
    } else {
        inv = ((len - 1) / 2 * len) - inv;
    }
    
    int start = N - len;
    reverse(a, start, N - 1);
    circle(a, start, start + inv);
    for(int i = 0; i < N; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int N,inv;
    while(cin>>N>>inv) {
        if(N == -1) {
            break;
        }
    
        a = new int[N];
        for(int i = 0; i < N; i++) {
            a[i] = i+1;
        }
        solve(N, inv);
        delete[] a;
    }
    return 0;
}
