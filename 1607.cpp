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

void solve(int n) {
    double d = 0.0;
    for(int i = n; i >= 1; i--) {
        d += (1 / (double)i);
    }
    d /= 2.0;

    printf("%5d%10.3lf\n",n, d);
}

int main() {
    int n;
    printf("Cards  Overhang\n");
    while(cin>>n) {
        solve(n);
    }

    return 0;
}
