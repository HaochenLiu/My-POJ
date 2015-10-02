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

long long gcd(long long a, long long b) {
    if(a == b) return a;
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b) * b);
}

int getCycle(int* a, int idx) {
    int cnt = 1;
    int input = idx;
    while(input != a[idx]) {
        idx = a[idx];
        cnt++;
    }
    return cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    int* a = new int[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int res = 1;
    for(int i = 0; i < N; i++) {
        res = lcm(res, getCycle(a, i));
    }

    delete[] a;
    cout<<res<<endl;

    return 0;
}
