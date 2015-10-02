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

char a[1000000];

bool test(int per) {
    int len = strlen(a);
    for(int i = 0; i < per; i++) {
        for(int j = 1; j < len / per; j++) {
            if(a[i] != a[i + j * per]) {
                return false;
            }
        }
    }
    return true;
}

int solve() {
    int len = strlen(a);
    for(int i = 1; i <= len; i++) {
        if(len % i == 0) {
            if(test(i)) {
                return len / i;
            }
        }
    }
    return 1;
}

int main() {
    while(true) {
        scanf("%s", a);
        if(strlen(a) == 1 && a[0] == '.') {
            break;
        }

        cout<<solve()<<endl;
    }
    return 0;
}
